object frmAbout: TfrmAbout
  Left = 311
  Top = 233
  BorderStyle = bsDialog
  Caption = #54532#47196#44536#47016#51221#48372
  ClientHeight = 218
  ClientWidth = 319
  Color = clBtnFace
  Font.Charset = HANGEUL_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #44404#47548
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 12
  object lbTitle: TLabel
    Left = 64
    Top = 32
    Width = 182
    Height = 35
    Caption = 'SnakeByte'
    Font.Charset = HANGEUL_CHARSET
    Font.Color = clRed
    Font.Height = -35
    Font.Name = #44404#47548
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lbVersion: TLabel
    Left = 232
    Top = 72
    Width = 43
    Height = 13
    Caption = 'Ver 0.1'
    Font.Charset = HANGEUL_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = #44404#47548
    Font.Style = []
    ParentFont = False
  end
  object lbInfo: TLabel
    Left = 168
    Top = 120
    Width = 88
    Height = 12
    Caption = #51228#51089#51088' :  '#54861#50896#51032
  end
  object brnOk: TButton
    Left = 128
    Top = 176
    Width = 75
    Height = 25
    Caption = #54869#51064
    TabOrder = 0
    OnClick = brnOkClick
  end
end
