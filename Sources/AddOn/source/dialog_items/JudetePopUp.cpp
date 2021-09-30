#include "include/dialog_items/JudetePopUp.h"
#include "source.cpp"
GIS::JudetePopUp::JudetePopUp(const DG::Panel & _panel, short item) :PopUp(_panel, item), PopUpObserver()
{
	Attach(*this);
	this->Fill(GIS::JUDETE_UAT);
	
}

GIS::JudetePopUp::~JudetePopUp()
{
	Detach(*this);
}



void GIS::JudetePopUp::PopUpChanged(const DG::PopUpChangeEvent & ev)
{
	
	JudetePopUp* source = dynamic_cast<JudetePopUp*>(ev.GetSource());
	
}

void GIS::JudetePopUp::FillOtherPopUpItem(const DG::PopUp &)
{
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
