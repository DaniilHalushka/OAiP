object Form1: TForm1
  Left = 257
  Top = 225
  Width = 1058
  Height = 675
  Caption = #1051#1072#1073#1086#1088#1072#1090#1086#1088#1085#1072#1103' '#1088#1072#1073#1086#1090#1072' '#8470'5'
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -24
  Font.Name = 'Times New Roman'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 27
  object Label1: TLabel
    Left = 48
    Top = 80
    Width = 119
    Height = 27
    Caption = #1042#1074#1077#1076#1080#1090#1077'  N:'
  end
  object Label2: TLabel
    Left = 56
    Top = 224
    Width = 84
    Height = 27
    Caption = #1052#1072#1089#1089#1080#1074':'
  end
  object Label3: TLabel
    Left = 48
    Top = 368
    Width = 944
    Height = 27
    Caption = 
      #1057#1091#1084#1084#1072' '#1084#1086#1076#1091#1083#1077#1081' '#1101#1083#1077#1084#1077#1085#1090#1086#1074' '#1084#1072#1089#1089#1080#1074#1072', '#1088#1072#1089#1087#1086#1083#1086#1078#1077#1085#1085#1099#1093' '#1087#1086#1089#1083#1077' '#1087#1077#1088#1074#1086#1075#1086' '#1101#1083#1077 +
      #1084#1077#1085#1090#1072', '#1088#1072#1074#1085#1086#1075#1086' '#1085#1091#1083#1102'.'
  end
  object Button1: TButton
    Left = 544
    Top = 64
    Width = 217
    Height = 49
    Caption = #1047#1072#1087#1086#1083#1085#1080#1090#1100' '#1084#1072#1089#1089#1080#1074
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 192
    Top = 72
    Width = 121
    Height = 35
    TabOrder = 1
  end
  object StringGrid1: TStringGrid
    Left = 48
    Top = 264
    Width = 849
    Height = 33
    ColCount = 2
    DefaultColWidth = 50
    DefaultRowHeight = 28
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object Memo1: TMemo
    Left = 40
    Top = 400
    Width = 961
    Height = 137
    Lines.Strings = (
      'Memo1')
    TabOrder = 3
  end
  object Button2: TButton
    Left = 456
    Top = 568
    Width = 129
    Height = 57
    Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100
    TabOrder = 4
    OnClick = Button2Click
  end
end
