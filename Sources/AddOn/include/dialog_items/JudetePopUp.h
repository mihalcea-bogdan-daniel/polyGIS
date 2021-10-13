#pragma once
#include "APIEnvir.h"
#include "ACAPinc.h"

#include "DGModule.hpp"
#include "Source.h"
#include "Preferences.h"
namespace GIS {
	
	class JudetePopUp : public DG::PopUp, public DG::PopUpObserver, public Preferences {
	public:
		JudetePopUp(const DG::Panel &_panel, short item);
		~JudetePopUp();
		void	SetPreferences();
		virtual void	PopUpChanged(const DG::PopUpChangeEvent& ev) override;
		
		void			Fill(const GS::HashTable<GS::UniString, GS::UShort>& hashtable);
		void			Fill(DG::PopUp &PopUp, const GS::Array<GIS::Localitate> &itemsArray);
		
	private:
		GIS::Item customItemID;
	};
}
