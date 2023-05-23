//---------------------------------------------------------------------------

#ifndef mainFormH
#define mainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>

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
	void __fastcall LoadFileButtonClick(TObject *Sender);
private:	// User declarations
	TOpenDialog * OpenDialog;
	TSaveDialog * SaveDialog;

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
    __fastcall ~TForm1();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
