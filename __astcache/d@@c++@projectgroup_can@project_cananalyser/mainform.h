﻿//---------------------------------------------------------------------------

#ifndef mainFormH
#define mainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <list>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TButton *LoadFileButton;
	TListBox *FilenameListBox;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TMemo *Memo2;
	TListBox *IdListBox1;
	TListBox *IdListBox2;
	TLabel *Label1;
	void __fastcall LoadFileButtonClick(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall ComboBox2Change(TObject *Sender);
private:	// User declarations
	TOpenDialog * OpenDialog;
	TSaveDialog * SaveDialog;

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	__fastcall ~TForm1();
	void __fastcall LoadFile(UnicodeString filename);
	void __fastcall LoadIdListInListBox(std::list<int> * id_list, TListBox * list_box);
    void __fastcall UpdateComboBox(TComboBox * combo_box, TStrings * file_list);
	std::list<int> * __fastcall GetUniqueIdList(TObjectList * can_data_list);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
