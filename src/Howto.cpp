//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Howto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmHowto *frmHowto;
//---------------------------------------------------------------------------
__fastcall TfrmHowto::TfrmHowto(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmHowto::btnOkClick(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------
