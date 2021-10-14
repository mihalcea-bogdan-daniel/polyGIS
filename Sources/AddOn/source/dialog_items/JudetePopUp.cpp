#include "include/dialog_items/JudetePopUp.h"
#include "Source.h"
#include "HTTPHandler.h"
#include "MainDialog.h"
GIS::JudetePopUp::JudetePopUp(const DG::Panel & _panel, short item) :
	/*Init inherited classes*/
	PopUp(_panel, item),
	PopUpObserver(),
	Preferences()
{
	Attach(*this);
	this->Fill(GIS::JUDETE_UAT);
	this->customItemID = GIS::Item(this->GetPanel()->GetId(), this->GetId());
	if (this->prefs.lastSelectedItems[this->customItemID]) {
		this->SelectItem(this->prefs.lastSelectedItems[this->customItemID]);
	}
	else {
		this->SelectItem(1);
	}

}

GIS::JudetePopUp::~JudetePopUp()
{
	Detach(*this);
}

void GIS::JudetePopUp::SetPreferences()
{
	this->prefs.lastSelectedItems.Add(this->customItemID, this->GetSelectedItem());
	ACAPI_SetPreferences(this->version, this->nBytes, &this->prefs);
}

void GIS::JudetePopUp::PopUpChanged(const DG::PopUpChangeEvent& ev)
{
	GS::Array<GIS::Localitate> listaLocalitati = {  };
	//Cast the source to a JudetePopUp class
	JudetePopUp* source = dynamic_cast<JudetePopUp*>(ev.GetSource());
	//Get the parent panel, needs casting
	GIS::MainDialog* parentPanel = dynamic_cast<MainDialog*>(source->GetPanel());

	DGUserData userData = DGPopUpGetItemUserData(DG_TOP_MODAL, source->GetId(), this->GetSelectedItem());
	int err = GIS::HTTPHandler::RequestLocalitati(userData, listaLocalitati);
	if (err == 200) {
		DG::PopUp* toFillpopup = dynamic_cast<DG::PopUp*>(parentPanel->GetItem(MainDialog::LocalitatiListBoxId));
		this->Fill(*toFillpopup, listaLocalitati);
		for (GIS::Localitate elem : listaLocalitati) {
			DBPrintf("%s\n", elem.UAT);
		}
		this->prefs.listaLocalitati = listaLocalitati;
	}
	this->SetPreferences();
}


void GIS::JudetePopUp::Fill(const GS::HashTable<GS::UniString, GS::UShort>& hashtable)
{
	short i{ 1 };
	for (auto elem : hashtable) {
		DGUserData OID = (int)*elem.value;
		this->InsertItem(i);
		this->SetItemValue(i, OID);
		this->SetItemText(i, *elem.key);
		i++;
	}
}

void GIS::JudetePopUp::Fill(DG::PopUp					     &PopUp,
	const GS::Array<GIS::Localitate> &itemsArray)
{
	DGPopUpDeleteItem(DG_TOP_MODAL, PopUp.GetId(), DG_ALL_ITEMS);
	short i{ 1 };
	for (auto element : itemsArray) {
		PopUp.InsertItem(i);
		PopUp.SetItemText(i, element.UAT);
		PopUp.SetItemValue(i, (int)element.ADMINISTRATIVEUNITID);
		i++;
	}
}
