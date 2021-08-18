#pragma once
#include "APIEnvir.h"
#include "ACAPinc.h"

#include	"HTTP/Client/ClientConnection.hpp"


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
		static void ReadJSONResponse();
		HTTPHandler();
		~HTTPHandler();
	};
}
