#pragma once
#include "APIEnvir.h"
#include "ACAPinc.h"

#include "DGModule.hpp"
#include "Source.h"
#include "./dialog_items/Preferences.h"

namespace GIS {
	class GIS_CheckBox:public DG::CheckBox, public DG::CheckItemObserver, public Preferences
	{
	public:
		GIS_CheckBox(const DG::Panel& _panel, short item);
		~GIS_CheckBox();
		virtual void			CheckItemChanged(const DG::CheckItemChangeEvent& ev) override;

	private:
		void GetStateFromPreferences();
	};

}