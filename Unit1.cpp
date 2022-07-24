//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

#include "MTrand.hpp"

MTRand *rnd;

Graphics::TBitmap *bmp;

// Размеры сети N

#define SZ_N 100

bool start=0;

int posAL[SZ_N][SZ_N];
int posAN[SZ_N][SZ_N];

int posO[SZ_N][SZ_N];

char net[SZ_N][SZ_N];

int numbit=0;

char old_bit=0;

// Чтение значения из бесконечного регистра

// p – позиция в регистре, целое число не равное нулю

char InfReg (int p)
{
  if (!p) return 55;

  int a=1, f=1, i=0;

  if (p<0)
  {
	f=0; p=-p;
  }

  for (; i<p; a++) i+=a;

  return (a%2)^f;
}

// Обработка одного цифрового маятника

char DigitalM(char L, char R, int i, int j)
{
  char rz=L^R;

  if (rz)
  {
	// Обработка Альфа значений маятника

	posAN[i][j]++;

	if (posAN[i][j]>=posAL[i][j])
	{
	  posAL[i][j]++;

	  posAN[i][j]=0;
	}

	// Обработка Омега значений маятника

	posO[i][j]++;

	if (!posO[i][j]) posO[i][j]++;
  }
  else
  {
	// Обработка Омега значений маятника

	posO[i][j]--;

	if (!posO[i][j]) posO[i][j]--;
  }

  char bitA=posAL[i][j]%2;

  rz^=InfReg(posO[i][j])^bitA;

  return rz;
}

// Инициализировать генератор случайных чисел

void ResetRnd()
{
  for (int i=0;i<SZ_N;i++)
  {
	for (int j=0;j<SZ_N;j++)
	{
	  net[i][j]=0;

	  posAL[i][j]=1;
	  posAN[i][j]=0;

	  posO[i][j]=1+rnd->randInt()%100;

	  if (rnd->randInt()%2)
	  {
		posO[i][j]*=-1;
	  }
	}
  }
  for (int j=0;j<SZ_N;j++)
  {
	net[0][j]=rnd->randInt()%2;
  }

  old_bit=net[0][0];

  numbit=0;
}

// Сгенерировать один абсолютно случайный бит

bool RndBit()
{
  // Сдвиг массива входных данных

  for (int j=SZ_N-1;j>0;j--)
  {
	net[0][j]=net[0][j-1];
  }

  // Подача сгенерированного бита на левый вход сети

  net[0][0]=old_bit;

  // Обработка сигналов хаотической треугольной сети

  for (int i=0;i<SZ_N-1;i++)
  {
	for (int j=0;j<SZ_N-i;j++)
	{
	  net[i+1][j]=DigitalM(net[i][j],net[i][j+1],i,j);
	}
  }

  old_bit=net[SZ_N-1][0];

  numbit++;

  return old_bit;
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
  // Инициализация генератора случайных чисел и графики

  rnd = new MTRand();

  bmp = new Graphics::TBitmap();

  bmp->Width=SZ_N*2;

  bmp->Height=SZ_N;

  bmp->PixelFormat = pf24bit;

//  reg = (char *)malloc(SZ_R);

  DoubleBuffered=1;

  // Инициализация треугольной хаотической сети

  ResetRnd();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
  delete rnd, bmp;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormPaint(TObject *Sender)
{
  // Отрисовка треугольной хаотической сети

  bool flag=CheckBox1->Checked;

  int max=0, min=0;

  // Нахождение минимумов и максимумов маятников
  for (int i=0;i<SZ_N;i++)
  {
    for (int j=0;j<SZ_N-i;i++)
    {
  	if (posO[i][j]>max)
  	{
  	  max=posO[i][j];
  	}
  	if (posO[i][j]<min)
  	{
  	  min=posO[i][j];
  	}
    }
  }

  char tt[100];

  sprintf(tt,"Максимальный маятник: %ld",max);

  Label1->Caption=tt;

  Label1->Font->Color=(TColor)RGB(0,100,200);

  sprintf(tt,"Минимальный маятник: %ld",min);

  Label2->Caption=tt;

  Label2->Font->Color=(TColor)RGB(200,100,0);

  sprintf(tt,"Всего сгенерировано бит: %ld",numbit);

  Label3->Caption=tt;

  int cl, ps;

  // Прорисовка треугольной хаотической сети

  for (int i=0;i<SZ_N;i++)
  {
	unsigned char *b=(unsigned char*)bmp->ScanLine[i];

	for (int j=0;j<SZ_N;j++)
	{
	  b[j*6+0]=128;
	  b[j*6+1]=128;
	  b[j*6+2]=128;
	  b[j*6+3]=128;
	  b[j*6+4]=128;
	  b[j*6+5]=128;
	}

	for (int j=0;j<SZ_N-i;j++)
	{
	  ps = 2*j+i;

	  if (!flag)
	  {
		b[ps*3+0]=net[i][j]*255;
		b[ps*3+1]=net[i][j]*255;
		b[ps*3+2]=net[i][j]*255;
		b[ps*3+3]=net[i][j]*255;
		b[ps*3+4]=net[i][j]*255;
		b[ps*3+5]=net[i][j]*255;
	  }
	  else
	  {
		if (posO[i][j]>0)
		{
		  cl=(255*posO[i][j])/max;

		  if (cl>255) cl=255;

		  b[ps*3+0]=cl;
		  b[ps*3+1]=cl/2;
		  b[ps*3+2]=0;
		  b[ps*3+3]=cl;
		  b[ps*3+4]=cl/2;
		  b[ps*3+5]=0;
		}
		else
		{
		  cl=(255*posO[i][j])/min;

		  if (cl>255) cl=255;

		  b[ps*3+0]=0;
		  b[ps*3+1]=cl/2;
		  b[ps*3+2]=cl;
		  b[ps*3+3]=0;
		  b[ps*3+4]=cl/2;
		  b[ps*3+5]=cl;
		}
	  }
	}
  }

  TRect r;

  r.top=PaintBox1->Top;

  r.left=PaintBox1->Left;

  r.bottom=PaintBox1->Top+PaintBox1->Height;

  r.right=PaintBox1->Left+PaintBox1->Width;

  Canvas->Pen->Color=clRed;

  Canvas->Rectangle(r.left-1,r.top-1,r.right+1,r.bottom+1);

  Canvas->StretchDraw(r,bmp);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  for (int z=0;z<100;z++)
  {
	RndBit();
  }

  Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  ResetRnd();

  Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
  start^=1;

  if (start)
  {
	Button3->Caption="Остановить генератор";
  }
  else
  {
	Button3->Caption="Запуск генератора";
  }

  Timer1->Enabled=start;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
  Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  Memo1->Lines->Clear();

  char tt[100];

  for (int i=-36;i<=36;i++)
  {
	int zn=InfReg(i);

	sprintf(tt,"%3ld: %ld",i,zn);

	Memo1->Lines->Add(tt);
  }

  Memo1->Lines->Add("-----------------------");

/*
  posAN[0][0]=0;
  posAL[0][0]=1;

  for (int i=0;i<50;i++)
  {
	sprintf(tt,"%3ld: %ld",i,posAL[0][0]%2);

	Memo1->Lines->Add(tt);

	posAN[0][0]++;

	if (posAN[0][0]>=posAL[0][0])
	{
	  posAL[0][0]++;

	  posAN[0][0]=0;
	}
  }
*/
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
  char txt[5001];

  int pp=0;

  char bt;

  for (int i=0;i<5000;i++)
  {
	bt=RndBit();

    pp+=bt;

	txt[i]=bt+'0';
  }

  txt[5000]=0;

  Memo1->Lines->Add(txt);

  Memo1->Lines->Add("-----------------------");

  sprintf(txt,"%ld",pp);

  Memo1->Lines->Add(txt);

  Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
  Memo1->Lines->Add(RndBit());

  Repaint();
}
//---------------------------------------------------------------------------

