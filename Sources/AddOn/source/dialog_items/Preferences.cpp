#include "./dialog_items/Preferences.h"
namespace GIS {

	Preferences::Preferences()
	{
		ACAPI_GetPreferences(&this->version, &this->nBytes, &this->prefs);
	}

	Preferences::~Preferences()
	{
	}

}
