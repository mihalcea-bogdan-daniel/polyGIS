#pragma once
#include "APIEnvir.h"
#include "ACAPinc.h"

#include "DGModule.hpp"
#include "Source.h"
namespace GIS {
	/*
	This class opens the preferences to all dialog items
	If a class must access the preferences it must inherit this
	*/
	class Preferences
	{
	public:
		Preferences();
		~Preferences();
	protected:
		Int32				version;
		GSSize				nBytes;
		AddOnPreferences	prefs;
	private:
		
	};

}