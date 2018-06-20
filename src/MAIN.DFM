object frmMain: TfrmMain
  Left = 192
  Top = 107
  BorderStyle = bsSingle
  Caption = 'SnakeByte'
  ClientHeight = 401
  ClientWidth = 532
  Color = clBtnFace
  Font.Charset = HANGEUL_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #44404#47548
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = formCreate
  OnKeyDown = KeyDown
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 12
  object gbScoreBox: TGroupBox
    Left = 408
    Top = 0
    Width = 121
    Height = 105
    Caption = ' '#51216#49688' '
    TabOrder = 0
    object lbScore: TLabel
      Left = 96
      Top = 48
      Width = 11
      Height = 19
      Alignment = taRightJustify
      Caption = '0'
      Font.Charset = HANGEUL_CHARSET
      Font.Color = clRed
      Font.Height = -19
      Font.Name = #44404#47548
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object MainMenu1: TMainMenu
    Left = 65528
    object miFile: TMenuItem
      Caption = #54028#51068'(&F)'
      object miFileNew: TMenuItem
        Caption = #49352' '#44172#51076'(&N)'
        OnClick = miFileNewClick
      end
      object miFilePause: TMenuItem
        Caption = #51068#49884#51221#51648'(&P)'
        OnClick = miFilePauseClick
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object miFileExit: TMenuItem
        Caption = #51333#47308'(&X)'
        OnClick = miFileExitClick
      end
    end
    object miHelp: TMenuItem
      Caption = #46020#50880#47568'(&H)'
      object miHelpHowto: TMenuItem
        Caption = #44172#51076#48169#48277'(&G)'
        OnClick = miHelpHowtoClick
      end
      object miHelpAbout: TMenuItem
        Caption = #54532#47196#44536#47016#51221#48372'(&A)'
        OnClick = miHelpAboutClick
      end
    end
  end
  object tmTimer: TTimer
    Interval = 250
    OnTimer = OnTimer
    Left = 24
  end
end
