#include "MainDialog.h"

#include "APIEnvir.h"
#include "ACAPinc.h"

#include "ResourceIds.hpp"
#include "DGModule.hpp"


namespace GIS {
	MainDialog::MainDialog() :
		DG::ModalDialog(ACAPI_GetOwnResModule(), MainDialogResourceId, ACAPI_GetOwnResModule()),
		okButton(GetReference(), OKButtonId),
		cancelButton(GetReference(), CancelButtonId),
		separator(GetReference(), SeparatorId),
		canvas(GetReference(), CanvasId)
	{
		AttachToAllItems(*this);
		Attach(*this);
		canvas.SetBackground(Gfx::Color(255, 255, 0));
	}
	MainDialog::~MainDialog() {
		Detach(*this);
		DetachFromAllItems(*this);
	}
	void MainDialog::PanelResized(const DG::PanelResizeEvent & ev) {
		BeginMoveResizeItems();
		okButton.Move(ev.GetHorizontalChange(), ev.GetVerticalChange());
		cancelButton.Move(ev.GetHorizontalChange(), ev.GetVerticalChange());
		separator.MoveAndResize(0, ev.GetVerticalChange(), ev.GetHorizontalChange(), 0);
		EndMoveResizeItems();
	}
	void MainDialog::ButtonClicked(const DG::ButtonClickEvent & ev) {
		if (ev.GetSource() == &okButton) {
			PostCloseRequest(DG::ModalDialog::Accept);
		}
		else if (ev.GetSource() == &cancelButton) {
			PostCloseRequest(DG::ModalDialog::Cancel);
		}
	}
}