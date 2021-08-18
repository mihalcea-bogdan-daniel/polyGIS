#include "APIEnvir.h"
#include "ACAPinc.h"

#include "ResourceIds.hpp"
#include "DGModule.hpp"
#include "StringConversion.hpp"
#include "HTTPHandler.h"
#include "MainDialog.h"

static const GSResID AddOnInfoID = ID_ADDON_INFO;
static const Int32 AddOnNameID = 1;
static const Int32 AddOnDescriptionID = 2;

static const short AddOnMenuID = ID_ADDON_MENU;
static const Int32 AddOnCommandID = 1;


static GSErrCode MenuCommandHandler(const API_MenuParams *menuParams)
{
	DBPrintf("item index: %u", menuParams->menuItemRef.itemIndex);
	switch (menuParams->menuItemRef.menuResID) {
	case AddOnMenuID:
		switch (menuParams->menuItemRef.itemIndex) {
		case AddOnCommandID:
		{
			DBPrintf("========================Debug started============================");
			//GIS::HTTPHandler::ReadJSONResponse();
			GIS::MainDialog dialog;
			dialog.Invoke();
		}
		break;
		}
		break;
	}
	return NoError;
}

API_AddonType __ACDLL_CALL CheckEnvironment(API_EnvirParams* envir)
{
	RSGetIndString(&envir->addOnInfo.name, AddOnInfoID, AddOnNameID, ACAPI_GetOwnResModule());
	RSGetIndString(&envir->addOnInfo.description, AddOnInfoID, AddOnDescriptionID, ACAPI_GetOwnResModule());

	return APIAddon_Normal;
}

GSErrCode __ACDLL_CALL RegisterInterface(void)
{
	return ACAPI_Register_Menu(AddOnMenuID, 0, MenuCode_Tools, MenuFlag_Default);
}

GSErrCode __ACENV_CALL Initialize(void)
{
	return ACAPI_Install_MenuHandler(AddOnMenuID, MenuCommandHandler);
}

GSErrCode __ACENV_CALL FreeData(void)
{
	return NoError;
}
