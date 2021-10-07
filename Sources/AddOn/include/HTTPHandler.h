#pragma once
#include "APIEnvir.h"
#include "ACAPinc.h"

#include "HTTP/Client/ClientConnection.hpp"
#include "Source.h"

namespace GIS {

	class HTTPHandler
	{
	public:
		static HTTP::MessageHeader::StatusCode::Id polyGISRequest(
			HTTP::MessageHeader::Method::Id method, 
				   const GS::UniString& URL, 
				   const GS::UniString& requestBody, 
						 GS::UniString& _response
		);
		static HTTP::MessageHeader::StatusCode::Id eTerraRequest(
			HTTP::MessageHeader::Method::Id method, 
				   const GS::UniString& URL, 
				   const GS::UniString& requestBody, 
						 GS::UniString& _response
		);

		/**
		Get the list of localities from eterra based on the selected county
		*/
		static HTTP::MessageHeader::StatusCode::Id RequestLocalitati(
			const GS::UInt64& UATID,
			GS::Array<GIS::Localitate>& _listaLocalitati
		);
		static HTTP::MessageHeader::StatusCode::Id RequestNumarCadastral(
			const GS::UInt64& UATID,
			const GS::UInt64& ADMINISTRATIVE_ID,
			const int& NUMAR_CADASTRAL
		);

		static void ReadJSONResponse();
		HTTPHandler();
		~HTTPHandler();
	};
}
