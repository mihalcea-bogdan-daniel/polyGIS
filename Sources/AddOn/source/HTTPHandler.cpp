#include "APIEnvir.h"
#include "ACAPinc.h"

#include	"HTTP/Client/ClientConnection.hpp"
#include	"HTTP/Client/Request.hpp"
#include	"HTTP/Client/Response.hpp"
#include	"HTTP/Client/Authentication/BasicAuthentication.hpp"
#include	"IBinaryChannelUtilities.hpp"
#include	"IOBinProtocolXs.hpp"
#include	"IChannelX.hpp"
#include	"StringConversion.hpp"

#include	"HTTPHandler.h"

//RapidJSON
#include	"document.h"
#include	"pointer.h"


namespace GIS {
	HTTP::MessageHeader::StatusCode::Id HTTPHandler::polyGISRequest(HTTP::MessageHeader::Method::Id method, const GS::UniString& URL, const GS::UniString& requestBody, GS::UniString& _response)
	{
		using namespace HTTP::Client;
		using namespace HTTP::MessageHeader;
		using namespace GS::IBinaryChannelUtilities;

		HTTP::MessageHeader::StatusCode::Id statusCode;
		IO::URI::URI connectionUrl(URL);

		ClientConnection clientConnection(connectionUrl);
		clientConnection.Connect();
		DBPrintf(requestBody.ToCStr().Get());
		DBPrintf("Method: %u\n", method);
		Request request(Method::Get, connectionUrl);

		request.GetRequestHeaderFieldCollection().Add(HeaderFieldName::Authorization, "ae95682a76654922b1d5ffce33ffd3f5");
		request.GetRequestHeaderFieldCollection().Add(HeaderFieldName::Host, "api.polygis.xyz");
		request.GetRequestHeaderFieldCollection().Add("Content-Type", "application/json");
		request.GetRequestHeaderFieldCollection().Add(HeaderFieldName::UserAgent,
			"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4515.131 Safari/537.36");

		clientConnection.Send(request, requestBody.ToCStr(), requestBody.GetLength());

		Response response;
		GS::IChannelX channel(clientConnection.BeginReceive(response), GS::GetNetworkByteOrderIProtocolX());
		_response = GS::IBinaryChannelUtilities::ReadUniStringAsUTF8(channel, StringSerializationType::NotTerminated);

		statusCode = response.GetStatusCode();
		clientConnection.FinishReceive();
		clientConnection.Close(true);
		return statusCode;
	}

	HTTP::MessageHeader::StatusCode::Id HTTPHandler::eTerraRequest(HTTP::MessageHeader::Method::Id method, const GS::UniString & URL, const GS::UniString & requestBody, GS::UniString & _response)
	{
		using namespace HTTP::Client;
		using namespace HTTP::MessageHeader;
		using namespace GS::IBinaryChannelUtilities;

		HTTP::MessageHeader::StatusCode::Id statusCode;
		IO::URI::URI connectionUrl(URL);

		ClientConnection clientConnection(connectionUrl);
		clientConnection.Connect();
		DBPrintf(requestBody.ToCStr().Get());
		Request request(method, connectionUrl);

		request.GetRequestHeaderFieldCollection().Add(HeaderFieldName::Host, "geoportal.ancpi.ro");
		request.GetRequestHeaderFieldCollection().Add(HeaderFieldName::Referer, "https://geoportal.ancpi.ro/geoportal/imobile/Harta.html");
		
		request.GetRequestHeaderFieldCollection().Add(HeaderFieldName::UserAgent,
			"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4515.131 Safari/537.36");

		clientConnection.Send(request, requestBody.ToCStr(), requestBody.GetLength());

		Response response;
		GS::IChannelX channel(clientConnection.BeginReceive(response), GS::GetNetworkByteOrderIProtocolX());
		_response = GS::IBinaryChannelUtilities::ReadUniStringAsUTF8(channel, StringSerializationType::NotTerminated);

		statusCode = response.GetStatusCode();
		clientConnection.FinishReceive();
		clientConnection.Close(true);
		return statusCode;
	}

	HTTP::MessageHeader::StatusCode::Id HTTPHandler::RequestLocalitati(const GS::UInt64& UATID, GS::Array<GIS::Localitate>& _listaLocalitati)
	{
		using namespace rapidjson;
		Document document;
		GS::UniString requestURL = "http://geoportal.ancpi.ro/geoprocessing/rest/services/LOOKUP/UATLookup/GPServer/FastSelect/execute?f=json&Expression=WORKSPACEID=" + GS::ValueToUniString(UATID);
		GS::UniString responseBody = "";

		HTTP::MessageHeader::StatusCode::Id statusCode = GIS::HTTPHandler::eTerraRequest(
			HTTP::MessageHeader::Method::Get,
			requestURL,
			"",
			responseBody
			);
		if (statusCode == 200) {
			document.Parse(responseBody.ToCStr().Get());
			if (Value* localitati = Pointer("/results/0/value/features").Get(document)) {
				GenericArray<false, Value::ValueType> listaLocalitati = localitati->GetArray();
				DBPrintf("Size of lista localiti %d\n", listaLocalitati.Size());
				for (SizeType i = 0; i < listaLocalitati.Size(); i++) {
					GenericObject<false, Value::ValueType> loc = listaLocalitati[i].GetObject();
					if (loc.HasMember("attributes")) {
						loc = loc["attributes"].GetObject();
						GIS::Localitate* localitate = new GIS::Localitate(loc["OID"].GetInt(), loc["ADMINISTRATIVEUNITID"].GetInt(), loc["UAT"].GetString());
						_listaLocalitati.Push(*localitate);
					}
				}

			}
		}
		
		return statusCode;
	}

	void HTTPHandler::ReadJSONResponse()
	{

		using namespace rapidjson;
		GS::UniString jsonString = "{\"uuid\" : 223}";
		Document document;
		document.Parse(jsonString.ToCStr().Get());
		if (Value* uuid = Pointer("/uuid").Get(document)) {
			DBPrintf("%d\n", uuid->GetInt());
		}
	}
	HTTPHandler::HTTPHandler() {};
	HTTPHandler::~HTTPHandler() {};
}