object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Main'
  ClientHeight = 653
  ClientWidth = 941
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 838
    Top = 147
    Width = 95
    Height = 15
    Caption = 'List of loaded files'
  end
  object Memo1: TMemo
    Left = 8
    Top = 37
    Width = 297
    Height = 292
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object LoadFileButton: TButton
    Left = 858
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Load File'
    TabOrder = 1
    OnClick = LoadFileButtonClick
  end
  object FilenameListBox: TListBox
    Left = 632
    Top = 168
    Width = 301
    Height = 422
    ItemHeight = 15
    TabOrder = 2
  end
  object ComboBox1: TComboBox
    Left = 8
    Top = 8
    Width = 145
    Height = 23
    TabOrder = 3
    Text = 'ComboBox1'
    OnChange = ComboBox1Change
  end
  object ComboBox2: TComboBox
    Left = 311
    Top = 8
    Width = 145
    Height = 23
    TabOrder = 4
    Text = 'ComboBox2'
    OnChange = ComboBox2Change
  end
  object Memo2: TMemo
    Left = 311
    Top = 37
    Width = 297
    Height = 292
    Lines.Strings = (
      'Memo1')
    TabOrder = 5
  end
  object IdListBox1: TListBox
    Left = 8
    Top = 335
    Width = 297
    Height = 254
    ItemHeight = 15
    TabOrder = 6
  end
  object IdListBox2: TListBox
    Left = 311
    Top = 335
    Width = 297
    Height = 254
    ItemHeight = 15
    TabOrder = 7
  end
end
