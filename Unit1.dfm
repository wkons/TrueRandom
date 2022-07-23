object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = '   2. '#1048#1057#1058#1048#1053#1053#1054' '#1057#1051#1059#1063#1040#1049#1053#1067#1045' '#1063#1048#1057#1051#1040
  ClientHeight = 478
  ClientWidth = 751
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object PaintBox1: TPaintBox
    Left = 337
    Top = 34
    Width = 400
    Height = 400
  end
  object Label1: TLabel
    Left = 599
    Top = 11
    Width = 138
    Height = 14
    Alignment = taRightJustify
    Caption = #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1099#1081' '#1084#1072#1103#1090#1085#1080#1082':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 337
    Top = 11
    Width = 134
    Height = 14
    Caption = #1052#1080#1085#1080#1084#1072#1083#1100#1085#1099#1081' '#1084#1072#1103#1090#1085#1080#1082':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 11
    Top = 11
    Width = 164
    Height = 14
    Caption = #1042#1089#1077#1075#1086' '#1089#1075#1077#1085#1077#1088#1080#1088#1086#1074#1072#1085#1086' '#1073#1080#1090':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Button1: TButton
    Left = 11
    Top = 445
    Width = 82
    Height = 25
    Caption = #1056#1077#1075#1080#1089#1090#1088
    TabOrder = 0
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 11
    Top = 34
    Width = 312
    Height = 400
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object CheckBox1: TCheckBox
    Left = 615
    Top = 447
    Width = 122
    Height = 21
    Caption = #1055#1086#1079#1080#1094#1080#1080' '#1084#1072#1103#1090#1085#1080#1082#1086#1074
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = CheckBox1Click
  end
  object Button2: TButton
    Left = 495
    Top = 445
    Width = 98
    Height = 25
    Caption = #1057#1073#1088#1086#1089#1080#1090#1100' '#1089#1077#1090#1100
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 354
    Top = 445
    Width = 135
    Height = 25
    Caption = #1047#1072#1087#1091#1089#1082' '#1075#1077#1085#1077#1088#1072#1090#1086#1088#1072
    TabOrder = 4
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 216
    Top = 445
    Width = 132
    Height = 25
    Caption = #1043#1077#1085#1077#1088#1072#1094#1080#1103' 1000 '#1073#1080#1090#1086#1074
    TabOrder = 5
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 99
    Top = 445
    Width = 111
    Height = 25
    Caption = #1043#1077#1085#1077#1088#1072#1094#1080#1103' 1 '#1073#1080#1090#1072
    TabOrder = 6
    OnClick = Button5Click
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 1
    OnTimer = Timer1Timer
    Left = 352
    Top = 47
  end
end
