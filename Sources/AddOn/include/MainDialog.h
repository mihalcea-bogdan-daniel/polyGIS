#pragma once
#include "APIEnvir.h"
#include "ACAPinc.h"

#include "ResourceIds.hpp"
#include "DGModule.hpp"

namespace GIS {

	class MainDialog : public DG::ModalDialog,
		public DG::PanelObserver,
		public DG::ButtonItemObserver,
		public DG::CompoundItemObserver
	{
	public:
		enum MainDialogResourceIds {
			MainDialogResourceId = ID_ADDON_DLG,
			OKButtonId = 1,
			CancelButtonId = 2,
			SeparatorId = 3
		};
		MainDialog();
		~MainDialog();
	private:
		virtual void PanelResized(const DG::PanelResizeEvent& ev) override ;
		virtual void ButtonClicked(const DG::ButtonClickEvent& ev) override ;
		DG::Button okButton;
		DG::Button cancelButton;
		DG::Separator separator;
	};



}