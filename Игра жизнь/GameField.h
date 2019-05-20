#pragma once

#include "GameModel.h"
using namespace System;
using namespace System::Drawing;

ref class GameField :public GameModel
{
	Object^ lock = gcnew Object();
	Graphics^ mainG;//Основной (видимый) холст
	Graphics^ g; //Холст в памяти
	BufferedGraphics^ bg;//буффер
	int w, h;
	void CreateDblBuff();//определяем буфер
	Point GetCell(int i, int j);
	void PaintCell(Rectangle r, bool status,bool nextstatus);
	void Start();
	bool started = false;
	Threading::Thread^ t;//поток старт потока t
	value struct Box
	{
		int dx, dy; //Сдвиг поля от начала координат
		int w, h; //Полезная ширина и высота поля
		int wsz, hsz;// Ширина и высота клеток на поле
		Box(int w, int h, int rows, int cols)
		{
			wsz = w / cols;
			hsz = h / rows;
			this->w = wsz * cols;
			this->h = hsz * rows;
			dx = (w - this->w) / 2;
			dy = (h - this->h) / 2;
		}
	};
public:
	int speed;
	GameField(int w, int h, Graphics^ g);
	GameField(int rows, int cols, int w, int h, Graphics^ g);
	//Прорисовка текущего состояния игрового поля
	void Paint();//рисование поля
	void ChangeState(int x, int y);//изменить статус
	void NextGeneration() override;//переоперделение
	void StartLife();
	void StopLife();
	//void SetSpeed(int value);
	~GameField();
	void Update(int width, int height, Graphics^ graphics);//обновленное поле
};

