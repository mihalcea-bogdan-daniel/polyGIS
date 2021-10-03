#include "Source.h"
#include "ResourceIds.hpp"


namespace GIS {
	
	//Set Default settings
	void MainFunctions::Do_SetDefaultSettings()
	{
		AddOnPreferences prefs;
		Int32 version;
		GSSize nBytes;

		unsigned short platformSign = GS::Act_Platform_Sign;
		ACAPI_GetPreferences_Platform(&version, &nBytes, nullptr, nullptr);
		if (version == CURR_ADDON_VERSION) {
			ACAPI_GetPreferences_Platform(&version, &nBytes, (GSPtr)&prefs, &platformSign);
			if (platformSign != GS::Act_Platform_Sign) {
				GS::PlatformSign	inplatform = (GS::PlatformSign) platformSign;
				IVLong(inplatform, &prefs.version);
				IVBool(inplatform, &prefs.absCoordinates);
				IVShort(inplatform, &prefs.lastSelectedJudet);
			}
		}
		else {
			// no preferences were saved before or incorrect preferences version
			//	--> fill with defaults
			BNZeroMemory(&prefs, sizeof(AddOnPreferences));
			prefs.version = CURR_ADDON_VERSION;
			prefs.absCoordinates = false;
			prefs.lastSelectedJudet = 1;
		}

		ACAPI_SetPreferences(CURR_ADDON_VERSION, sizeof(AddOnPreferences), (GSPtr)&prefs);

	}
}// DoSetDefaultSettings()