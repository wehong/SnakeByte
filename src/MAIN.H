//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------

enum dire { N, E, S, W };
struct snake
{
        int x, y;
        dire d;
};
enum pmode { STOP=0, PLAY, END, PAUSE };

class TfrmMain : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *miFile;
        TMenuItem *miFileExit;
        TTimer *tmTimer;
        TMenuItem *miFileNew;
        TMenuItem *N1;
        TMenuItem *miFilePause;
        TMenuItem *miHelp;
        TGroupBox *gbScoreBox;
        TLabel *lbScore;
        TMenuItem *miHelpHowto;
        TMenuItem *miHelpAbout;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall miFileExitClick(TObject *Sender);
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall miFileNewClick(TObject *Sender);
        void __fastcall OnTimer(TObject *Sender);
        void __fastcall KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall miFilePauseClick(TObject *Sender);
        void __fastcall miHelpHowtoClick(TObject *Sender);
        void __fastcall miHelpAboutClick(TObject *Sender);
private:	// User declarations
        Graphics::TBitmap *sn, *wa, *fr, *em, *fi;
        pmode playmode;
        snake s[400];
        int len;
        int tail;
        int fx, fy;
        int score;
public:		// User declarations
        __fastcall TfrmMain(TComponent* Owner);
        void ClearField();
        void Forward();
        void ShowSnake(bool b);
        void Check();
        void ThrowFruit();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
