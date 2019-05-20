#include "GameField.h"
using namespace System::Drawing::Drawing2D;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

Color Random1() {
	System::Random^rnd = gcnew System::Random();
	int r = rnd->Next(100, 255);
	int gr = rnd->Next(100, 255);
	int bl = rnd->Next(100, 255);
	Color c = Color::FromArgb(r, gr, bl);
	return c;
}
void GameField::CreateDblBuff()
{
	BufferedGraphicsContext^ bgc =
		BufferedGraphicsManager::Current;
	bg = bgc->Allocate(mainG, Rectangle(0, 0, w, h));//буфер
	g = bg->Graphics;
}
Point GameField::GetCell(int x, int y) //по точке определяет номер клетки
{
	Box b(w, h, Rows, Cols);
	Point p(-1, -1);
	if (
		x >= b.dx &&
		y >= b.dy &&
		x < b.w + b.dx &&
		y < b.h + b.dy
		)
	{
		p.Y = (x - b.dx) / b.wsz;//получаем номер строки
		p.X = (y - b.dy) / b.hsz;//получаем номер столбца
	}
	return p;
}
void GameField::PaintCell(Rectangle r,bool status,bool nextstatus)
{
	LinearGradientBrush^ lb;//кисть
	if (status)
	{
	 if (!nextstatus) {
		lb = gcnew LinearGradientBrush(//прямоугольник в светло оранжевый
			r,
			Color::Red,
			Color::Black,
			//Random1(),
			//Random1(),
			90);

	 }
	 else {
		 lb = gcnew LinearGradientBrush(//прямоугольник в светло оранжевый
			 r,
			 Color::OrangeRed,
			 Color::Coral,
			 //Random1(),
			 //Random1(),
			 90);
	 }
	}
	else
	{
		lb = gcnew LinearGradientBrush(//прямоугольник закрашенниый в серый
			r,
			Color::LightGray,
			Color::Gray,
			90
		);
	}
	Threading::Monitor::Enter(lock);//войти в поток
	g->FillRectangle(lb, r);
	Threading::Monitor::Exit(lock);//выйти из потока

}
void GameField::Start()
{
	while (started)
	{
		NextGeneration();
		Threading::Thread::Sleep(speed);
	}
}
GameField::GameField(int _w, int _h, Graphics^ g) :
	mainG(g), w(_w), h(_h)
{
	//this->speed = 50;
	CreateDblBuff();
}
GameField::GameField(int rows, int cols, int _w, int _h, Graphics^ g) :
	GameModel(rows, cols), mainG(g), w(_w), h(_h)
{
	//this->speed = 50;
	CreateDblBuff();
}
void GameField::Paint()
{
	Threading::Monitor::Enter(lock);
	g->Clear(Color::White);
	Threading::Monitor::Exit(lock);

	Pen^ p = gcnew Pen(Color::Gray);
	Box b(w, h, Rows, Cols);

	for (int i = b.dx; i < b.w + b.dx; i += b.wsz)
	{
		for (int j = b.dy; j < b.h + b.dy; j += b.hsz)
		{

			Rectangle r(i + 1, j + 1, b.wsz - 1, b.hsz - 1);//получил прямоугольник
			Point cell = GetCell(i, j);//номер прямоугольник
			bool status = Field[cell.X, cell.Y];//узнал статус прямоугольника с этим номером
			bool nextstatus = NextField[cell.X, cell.Y];
			PaintCell(r, status,nextstatus);//закрасил
		}
	}
	Threading::Monitor::Enter(lock);
	bg->Render();//вывео в панели
	Threading::Monitor::Exit(lock);
}
void GameField::ChangeState(int x, int y)
{
	Point p = GetCell(x, y);//по точке орпедеят номер клетки
	if (p.X != -1 && p.Y != -1)
	{
		Field[p.X, p.Y] = !Field[p.X, p.Y];
		Paint();//перерисовка если изменили
	}
}
void GameField::NextGeneration()
{
	GameModel::NextGeneration();
	Paint();
}
void GameField::StartLife()
{
	if (!started) {
		Threading::ThreadStart^ ts =
			gcnew Threading::ThreadStart(
				this,
				&GameField::Start
			);
		t = gcnew Threading::Thread(ts);
		t->Start();
		started = true;
	}

}
void GameField::StopLife()
{
	started = false;
	try {
		t->Abort();
		t->Join();
	}
	catch (...)
	{

	}
}

GameField::~GameField()
{
	StopLife();
}

void GameField::Update(int width, int height, Graphics^ graphics)
{	
	w = width;
	h = height;
    mainG = graphics;
	CreateDblBuff();
	Paint();
}

/*void GameField::SetSpeed(int value) 
{
	if (value > 0 && value < 150) {
		this->speed = value;
	}
}*/

