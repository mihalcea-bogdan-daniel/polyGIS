#include "dialog_items/GIS_CheckBox.h"
namespace GIS {
	GIS_CheckBox::GIS_CheckBox(const DG::Panel& _panel, short item) :
		CheckBox(_panel, item),
		CheckItemObserver(),
		Preferences()
	{
		Attach(*this);
		this->GetStateFromPreferences();
	}

	GIS_CheckBox::~GIS_CheckBox()
	{
		Detach(*this);
	}

	//OnCheckItemChanged
	void GIS_CheckBox::CheckItemChanged(const DG::CheckItemChangeEvent& ev)
	{
		GIS_CheckBox*		source = dynamic_cast<GIS_CheckBox*>(ev.GetSource());
		bool isChecked = source->IsChecked();
		
		//Change the preferences when clicked
		if (isChecked == true) {
			this->prefs.absCoordinates = 1;
		}
		else {
			this->prefs.absCoordinates = 0;
		}
		ACAPI_SetPreferences(this->version, this->nBytes, &this->prefs);
	}

	//Could be called InitCheckBox
	void GIS_CheckBox::GetStateFromPreferences()
	{

		if (this->prefs.absCoordinates == true) {
			this->Check();
		}
		else {
			this->Uncheck();
		}


	}
}