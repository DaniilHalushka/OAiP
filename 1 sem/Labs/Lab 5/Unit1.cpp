//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
 int n;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
Memo1->Clear();
        randomize();
        Edit1->Text=IntToStr(n);
        StringGrid1->ColCount=n;
        for(int i=0; i<n;i++)
                StringGrid1->Cells[i][0] = IntToStr(random(21)-10);
        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
n=StrToInt(Edit1->Text);
        if(n>10){
                ShowMessage("Максимальное количество 10!");
                n=10;
                Edit1->Text = "10";
        }
        StringGrid1->ColCount=n;
        for(int i=0; i<n;i++)
                StringGrid1->Cells[i][0]=IntToStr(random(5)-2);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        int i=0,a[10],k=0, sum=0;
        for(i=0; i<n;i++) {
              a[i]=StrToInt(StringGrid1->Cells[i][0]);
        }
        i=0;
        for(i=0; i<n;i++){
                if(a[i]==0) {
                k = i;
                  for(i=k; i<n;i++){
                      sum += fabs(a[i]);
                  }
                }
        }
        Memo1->Lines->Add(IntToStr(sum));
}
//---------------------------------------------------------------------------
