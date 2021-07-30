//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <string>


#include "Unit8.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
AnsiString eName[]={"landlord","jameson","samuel","hyperactive","whale","cardio","programming","screen","fortunes","riches","forver","grateful","billion","stratergy"};


//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button1Click(TObject *Sender)
{
	int i=0;
	bool found=false;

	String letter=Edit1->Text;
	 int counter=0;
	  int l=(Label2->Caption).Length();
	 if(l==0)
	 {
		  ShowMessage("Please generate a word");
	 }
	 else
	 {
	letter=letter.SubString(0,1);
	//label 3 stores the word user must get right
	AnsiString word=Label3->Caption;
	//guss stors * value of word
	AnsiString guss=Label2->Caption;



	bool guessT=false;

	for(int i=1;i<word.Length()+1;i=i+1)
	{
	   if(letter==word[i])
	   {
		   guss[i]=word[i];
		   guessT=true;

	   }
	}

	if(!guessT)
	{
		counter=counter+1;

	}




	AnsiString name= "..\\..\\Default";
	name=name+IntToStr(counter);
	name=name+".bmp";




	Label2->Caption=guss;
	Image1->Picture->Bitmap->LoadFromFile(name);
	Edit1->Clear();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm8::FormShow(TObject *Sender)
{
	//Image1->Picture->LoadFromFile("Default.jpeg");


	Edit1->Clear();

	Image1->Picture->Bitmap->LoadFromFile("..\\..\\Default0.bmp");
	//set Difficulty to easy when program starts
	//will auto increment depending on user

	ComboBox1->ItemIndex=1;




}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button2Click(TObject *Sender)
{
	int random = 0+rand()%14;
	AnsiString guess=eName[random];
	Image1->Picture->Bitmap->LoadFromFile("..\\..Default0.bmp");
	Label3->Caption=guess;


	int l= guess.Length();


	for(int i=1;i<guess.Length()+1;i=i+1)
	{
		guess[i]='*';
	}


	Label2->Caption=guess;


}
//---------------------------------------------------------------------------

