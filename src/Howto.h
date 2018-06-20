//---------------------------------------------------------------------------

#ifndef HowtoH
#define HowtoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TfrmHowto : public TForm
{
__published:	// IDE-managed Components
        TMemo *mmHowto;
        TButton *btnOk;
        void __fastcall btnOkClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmHowto(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmHowto *frmHowto;
//---------------------------------------------------------------------------
#endif
