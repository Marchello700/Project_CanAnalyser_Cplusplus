﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	OpenDialog = new TOpenDialog(this);
	SaveDialog = new TSaveDialog(this);
	OpenDialog->Filter = "Text files (*.txt)|*.TXT|Any file (*.*)|*.*";
	SaveDialog->Filter = "Text files (*.txt)|*.TXT|Any file (*.*)|*.*";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LoadFileButtonClick(TObject *Sender)
{
	if (this->OpenDialog->Execute()) {
		if (FileExists(OpenDialog->FileName)) {
			if (FilenameListBox->Items->IndexOf(OpenDialog->FileName) == -1) {
				FilenameListBox->AddItem(OpenDialog->FileName,NULL);
			}
		}
	}
}
//---------------------------------------------------------------------------
__fastcall TForm1::~TForm1()
{
	delete OpenDialog;
    delete SaveDialog;
}
