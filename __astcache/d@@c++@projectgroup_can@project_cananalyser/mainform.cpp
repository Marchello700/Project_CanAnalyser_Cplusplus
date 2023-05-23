//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainForm.h"
#include "CanData.h"
#include "CanParser.h"
#include <System.Generics.Collections.hpp>
#include <sstream>

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
				this->LoadFile(OpenDialog->FileName);
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
//---------------------------------------------------------------------------
void __fastcall TForm1::LoadFile(UnicodeString filename)
{
	TStringList * datafile = new TStringList();
	TCanDataFrame * can_data;
	TObjectList * can_data_frame_list = new TObjectList(true);
	datafile->LoadFromFile(OpenDialog->FileName);
	for (int i = 0; i < datafile->Count; i++) {
		//workaround to convert UnicodeString to std::string
		AnsiString ansiB(datafile->Strings[i]);
		char* str = new char[ansiB.Length()+1];
		strcpy(str, ansiB.c_str());
		//end of workaround
		can_data = CanParser::CanScannerParser(str);
		if (can_data != NULL) {
			can_data_frame_list->Add(can_data);            
		}
		delete[] str;
	}
	delete datafile;
	FilenameListBox->AddItem(OpenDialog->FileName,can_data_frame_list);
	this->UpdateComboBox(ComboBox1,FilenameListBox->Items);
	this->UpdateComboBox(ComboBox2,FilenameListBox->Items);
}
//---------------------------------------------------------------------------
std::list<int> * __fastcall TForm1::GetUniqueIdList(TObjectList * can_data_list)
{
	TStringList * result = new TStringList();
	TCanDataFrame * can_data;
	std::list<int> * id_list = new std::list<int>();
	for (auto item : can_data_list) {
		can_data = (TCanDataFrame*)item;
        std::list<int>::iterator findIter = std::find(id_list->begin(), id_list->end(), can_data->getId());
		if (findIter == id_list->end()) {
            id_list->push_back(can_data->getId());
        }
	}
	return id_list;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LoadIdListInListBox(std::list<int> * id_list, TListBox * list_box)
{
	for (auto id : *id_list) {
		std::ostringstream ss;
		ss << std::hex << id;
		std::string result = ss.str();
		list_box->AddItem(result.c_str(),NULL);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UpdateComboBox(TComboBox * combo_box, TStrings * file_list)
{
	combo_box->Clear();
	combo_box->Items->AddStrings(file_list);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
	System::UnicodeString str = this->ComboBox1->SelText;
	int index = this->FilenameListBox->Items->IndexOf(str);
	if (index == -1) {
		return;
	}
	//need to either get lists out of ListBox or change storage of <filename,data_list>
//	TObjectList * can_data_frame_list = this->FilenameListBox->Data[index];
	std::list<int> * id_list = this->GetUniqueIdList(can_data_frame_list);
	this->LoadIdListInListBox(id_list,this->IdListBox1);
	delete id_list;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
	//---
}
//---------------------------------------------------------------------------
