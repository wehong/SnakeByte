//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "Howto.h"
#include "About.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormCreate(TObject *Sender)
{
        sn = new Graphics::TBitmap();
        sn->LoadFromResourceName((int)HInstance, "SNAKE");

        wa = new Graphics::TBitmap();
        wa->LoadFromResourceName((int)HInstance, "WALL");


        fr = new Graphics::TBitmap();
        fr->LoadFromResourceName((int)HInstance, "FRUIT");

        em = new Graphics::TBitmap();
        em->LoadFromResourceName((int)HInstance, "EMPTY");

        fi = new Graphics::TBitmap();
        fi->Width = 400;
        fi->Height = 400;
        fi->Canvas->Brush->Color = clBlack;
        fi->Canvas->FillRect(Rect(0, 0, 400, 400));

        score = 0;
        lbScore->Caption = IntToStr(score);

        randomize();

        miFilePause->Enabled = false;
        playmode = STOP;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormClose(TObject *Sender, TCloseAction &Action)
{
        delete sn;
        delete wa;
        delete fr;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::miFileNewClick(TObject *Sender)
{
        len = 5;
        tail = 0;
        for(int i=0; i<5; i++)
        {
                s[i].x = 20;
                s[i].y = 20+i;
                s[i].d = N;
        }
        for(int i=5; i<400; i++)
        {
                s[i].x = 0;
                s[i].y = 0;
                s[i].d = N;
        }


        ThrowFruit();

        ClearField();

        score = 0;
        lbScore->Caption = IntToStr(score);
        miFilePause->Enabled = true;
        playmode = PLAY;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::miFileExitClick(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormPaint(TObject *Sender)
{
        ClearField();
        if(playmode!=STOP)
        {
                for(int i=0; i<len; i++)
                {
                        frmMain->Canvas->Draw(s[i].x*10, s[i].y*10, sn);
                }
                frmMain->Canvas->Draw(fx*10, fy*10, fr);
        }
        lbScore->Caption = IntToStr(score);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::OnTimer(TObject *Sender)
{
        if(playmode==PLAY)
        {
                ShowSnake(false);
                Forward();
                Check();
                ShowSnake(true);
                frmMain->Canvas->Draw(fx*10, fy*10, fr);
        }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(playmode==PLAY)
        {
                if(Key==VK_LEFT)
                {
                        switch(s[0].d)
                        {
                                case N :
                                        s[0].d = W;
                                        break;
                                case E :
                                        s[0].d = N;
                                        break;
                                case S :
                                        s[0].d = E;
                                        break;
                                case W :
                                        s[0].d = S;
                                        break;
                        }
                }
                if(Key==VK_RIGHT)
                {
                        switch(s[0].d)
                        {
                                case N :
                                        s[0].d = E;
                                        break;
                                case E :
                                        s[0].d = S;
                                        break;
                                case S :
                                        s[0].d = W;
                                        break;
                                case W :
                                        s[0].d = N;
                                        break;
                        }
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::miFilePauseClick(TObject *Sender)
{
        if(miFilePause->Checked == false)
        {
                miFilePause->Checked = true;
                playmode = PAUSE;
        }
        else
        {
                miFilePause->Checked = false;
                playmode = PLAY;
        }
}
//---------------------------------------------------------------------------

void TfrmMain::ClearField()
{
        frmMain->Canvas->Draw(0, 0, fi);
        for(int i=0; i<40; i++)
        {
                frmMain->Canvas->Draw(0, i*10, wa);
                frmMain->Canvas->Draw(390, i*10, wa);
                frmMain->Canvas->Draw(i*10, 0, wa);
                frmMain->Canvas->Draw(i*10, 390, wa);
        }
}

void TfrmMain::Forward()
{
        int tx = s[len-1].x;
        int ty = s[len-1].y;
        dire td = s[len-1].d;

        switch(s[0].d)
        {
                case N :
                        s[0].y -= 1;
                        break;
                case E :
                        s[0].x += 1;
                        break;
                case S :
                        s[0].y += 1;
                        break;
                case W :
                        s[0].x -= 1;
                        break;
        }
        for(int i=len-1; i>0; i--)
        {
                switch(s[i].d)
                {
                        case N :
                                s[i].y -= 1;
                                break;
                        case E :
                                s[i].x += 1;
                                break;
                        case S :
                                s[i].y += 1;
                                break;
                        case W :
                                s[i].x -= 1;
                                break;
                }
                s[i].d = s[i-1].d;
        }
        if(tail>0)
        {
                len += 1;
                if(len>=400)
                {
                        playmode = END;
                        ShowSnake(true);
                        miFilePause->Enabled = false;
                        ShowMessage("너무 길어져서 게임을 진행할 수 없습니다");
                        return;
                }
                s[len-1].x = tx;
                s[len-1].y = ty;
                s[len-1].d = td;
                tail--;
        }
}

void TfrmMain::ShowSnake(bool b)
{
        for(int i=0; i<len; i++)
        {
                if(b) frmMain->Canvas->Draw(s[i].x*10, s[i].y*10, sn);
                else frmMain->Canvas->Draw(s[i].x*10, s[i].y*10, em);
        }
}

void TfrmMain::Check()
{
        for(int i=1; i<len; i++) if(s[0].x==s[i].x && s[0].y==s[i].y)
        {
                playmode = END;
                ShowSnake(true);
                miFilePause->Enabled = false;
                ShowMessage("꼬리를 물었습니다");
        }
        if(s[0].x==0 || s[0].x==39 || s[0].y==0 || s[0].y==39)
        {
                playmode = END;
                ShowSnake(true);
                miFilePause->Enabled = false;
                ShowMessage("벽에 부딪혔습니다");
        }
        if(s[0].x==fx && s[0].y==fy)
        {
                Beep();
                score += 10;
                if(score>=65530) score = 65530;
                lbScore->Caption = IntToStr(score);
                tail += 4;
                tmTimer->Interval -= 10;
                if(tmTimer->Interval<100) tmTimer->Interval=100;
                ThrowFruit();
        }
}

void TfrmMain::ThrowFruit()
{
        bool flag;

        do
        {
                fx = random(38)+1;
                fy = random(38)+1;
                flag = false;
                for(int i=0; i<len; i++)
                {
                        if(fx==s[i].x && fy==s[i].y) flag = true;
                }
        } while(flag);
}


void __fastcall TfrmMain::miHelpHowtoClick(TObject *Sender)
{
        bool flag = false;

        if(playmode==PLAY)
        {
                playmode = PAUSE;
                flag = true;
        }
        TfrmHowto *howto = new TfrmHowto(this);
        TRect Rect = Application->MainForm->BoundsRect;
        howto->Left = ((Rect.right-Rect.left)-howto->Width)/2 + Rect.left;
        howto->Top = ((Rect.Bottom-Rect.top)-howto->Width)/2 + Rect.top;
        howto->ShowModal();
        delete frmHowto;
        if(flag) playmode = PLAY;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::miHelpAboutClick(TObject *Sender)
{
        bool flag = false;

        if(playmode==PLAY)
        {
                playmode = PAUSE;
                flag = true;
        }
        TfrmAbout *about = new TfrmAbout(this);
        TRect Rect = Application->MainForm->BoundsRect;
        about->Left = ((Rect.right-Rect.left)-about->Width)/2 + Rect.left;
        about->Top = ((Rect.Bottom-Rect.top)-about->Width)/2 + Rect.top;
        about->ShowModal();
        delete frmAbout;
        if(flag) playmode = PLAY;
}
//---------------------------------------------------------------------------

