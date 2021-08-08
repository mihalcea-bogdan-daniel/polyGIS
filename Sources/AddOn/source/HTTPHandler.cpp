#include "APIEnvir.h"
#include "ACAPinc.h"

#include "HTTPHandler.h"
#include "document.h"
#include "pointer.h"

namespace GIS {

	void HTTPHandler::ReadJSONResponse()
	{
		using namespace rapidjson;
		GS::UniString jsonString = "{\"uuid\" : 223}";
		Document document;
		document.Parse(jsonString.ToCStr().Get());
		if (Value* uuid = Pointer("/uuid").Get(document)) {
			DBPrintf("%d\n",uuid->GetInt());
		}
	}
	HTTPHandler::HTTPHandler() {};
	HTTPHandler::~HTTPHandler() {};
}