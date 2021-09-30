#pragma once
#include "APIEnvir.h"
#include "ACAPinc.h"

#include "DGModule.hpp"

namespace GIS {
	class JudetePopUp : public DG::PopUp, public DG::PopUpObserver {
	public:
		JudetePopUp(const DG::Panel &_panel, short item);
		~JudetePopUp();
		virtual void PopUpChanged(const DG::PopUpChangeEvent& ev) override;
		void FillOtherPopUpItem(const DG::PopUp&);
		void Fill(const GS::HashTable<GS::UniString, GS::UShort>& hashtable);
		GS::UniString name;
	};
}