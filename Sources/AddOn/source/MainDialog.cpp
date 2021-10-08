#include "MainDialog.h"

#include	"APIEnvir.h"
#include	"ACAPinc.h"

#include	"ResourceIds.hpp"
#include	"DGModule.hpp"

#include	"DGNativeContexts.hpp"
#include	"Graphics2D.h"
#include	"GXImage.hpp"
#include	"DGUtility.hpp"
#include	"HTTPHandler.h"
namespace GIS {
	MainDialog::MainDialog() :
		DG::ModalDialog(ACAPI_GetOwnResModule(), MainDialogResourceId, ACAPI_GetOwnResModule()),
		okButton(GetReference(), OKButtonId),
		cancelButton(GetReference(), CancelButtonId),
		separator(GetReference(), SeparatorId),
		canvas(GetReference(), CanvasId),
		judetePopUp(GetReference(), JudeteListBoxId),
		localitatiPopUp(GetReference(), LocalitatiListBoxId),
		numarCadastralIntInput(GetReference(), NumarCadastralIntInputId),
		searchButton(GetReference(), SearchButtontId),
		contactText(GetReference(), ContactTextId),
		aboutText(GetReference(), AboutTextId),
		donationButton(GetReference(), DonationButtontId),
		isAbsOriginCheckBox(GetReference(), IsAbsOriginCheckBoxId)
	{
		GIS::INIT::MainFunctions::Do_SetDefaultSettings();
		AttachToAllItems(*this);
		Attach(*this);
		canvas.SetBackground(Gfx::Color(180, 255, 0));
		

		//GS::UniString _resp;
		//HTTP::MessageHeader::StatusCode::Id requestStatus = GIS::HTTPHandler::polyGISRequest(HTTP::MessageHeader::Method::Get, "https://api.polygis.xyz", "{}", _resp);
		//if (requestStatus != NULL) {
		//	DBPrintf("Request Status: %u\n", requestStatus);

		//}

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
		canvas.MoveAndResize(0, 0, ev.GetHorizontalChange(), ev.GetVerticalChange());
		contactText.Move(0, ev.GetVerticalChange());
		aboutText.Move(0, ev.GetVerticalChange());
		donationButton.Move(0, ev.GetVerticalChange());
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

	//Draw a picture to the user item
	//static void DrawMyPict(DGUserUpdateData	*upd,
	//	GSHandle			picData)
	//{
	//	if (upd == 0 || upd->drawContext == 0 || picData == 0)
	//		return;

	//	const float width = (float)(upd->right - upd->left);
	//	const float height = (float)(upd->bottom - upd->top);

	//	NewDisplay::UserItemUpdateNativeContext context(upd);
	//	NewDisplay::NativeImage image = GX::Image(picData, FTM::UnknownType).ToNativeImage();

	//	const float xScale = (float)width / (float)image.GetWidth();
	//	const float yScale = (float)height / (float)image.GetHeight();

	//	context.DrawImage(image, xScale, yScale, 0.0, 0.0, 0.0, false);
	//}	// DrawMyPict
}