object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 642
  ClientWidth = 1062
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OnClose = FormClose
  TextHeight = 13
  object Label1: TLabel
    Left = 33
    Top = 47
    Width = 31
    Height = 13
    Caption = 'Label1'
  end
  object Label2: TLabel
    Left = 147
    Top = 47
    Width = 31
    Height = 13
    Caption = 'Label2'
  end
  object Label3: TLabel
    Left = 272
    Top = 47
    Width = 31
    Height = 13
    Caption = 'Label3'
  end
  object Image1: TImage
    Left = 660
    Top = 75
    Width = 640
    Height = 480
  end
  object Label4: TLabel
    Left = 781
    Top = 21
    Width = 31
    Height = 13
    Caption = 'Label4'
  end
  object Label5: TLabel
    Left = 538
    Top = 49
    Width = 501
    Height = 13
    Caption = 
      '0                     100                   200                 ' +
      '  300                   400                   500               ' +
      '    600       640'
  end
  object Label6: TLabel
    Left = 520
    Top = 136
    Width = 18
    Height = 13
    Caption = '100'
  end
  object Label7: TLabel
    Left = 520
    Top = 213
    Width = 18
    Height = 13
    Caption = '200'
  end
  object Label8: TLabel
    Left = 520
    Top = 296
    Width = 18
    Height = 13
    Caption = '300'
  end
  object Label9: TLabel
    Left = 520
    Top = 376
    Width = 18
    Height = 13
    Caption = '400'
  end
  object Label10: TLabel
    Left = 520
    Top = 440
    Width = 18
    Height = 13
    Caption = '480'
  end
  object B_CameraConnexion: TButton
    Left = 33
    Top = 16
    Width = 121
    Height = 25
    Caption = 'B_CameraConnexion'
    TabOrder = 0
    OnClick = B_CameraConnexionClick
  end
  object B_PrendrePhoto: TButton
    Left = 176
    Top = 16
    Width = 75
    Height = 25
    Caption = 'B_PrendrePhoto'
    TabOrder = 1
    OnClick = B_PrendrePhotoClick
  end
  object Edit1: TEdit
    Left = 289
    Top = 20
    Width = 121
    Height = 21
    TabOrder = 2
    Text = 'im1.bmp'
  end
  object B_OuvrirFichier: TButton
    Left = 416
    Top = 16
    Width = 75
    Height = 25
    Caption = 'B_OuvrirFichier'
    TabOrder = 3
    OnClick = B_OuvrirFichierClick
  end
  object B_DemoMarquage: TButton
    Left = 538
    Top = 18
    Width = 75
    Height = 25
    Caption = 'B_DemoMarquage'
    TabOrder = 4
    OnClick = B_DemoMarquageClick
  end
  object Button1: TButton
    Left = 700
    Top = 18
    Width = 75
    Height = 25
    Caption = 'Test'
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 936
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 6
    OnClick = Button2Click
  end
end
