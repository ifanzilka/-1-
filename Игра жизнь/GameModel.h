#pragma once

ref class GameModel
{
	int cols, rows;//количсетво клеток по столбцам и строкам
	array <bool, 2> ^field;//массив статусов клеток
	
	void RecreateArray();//пересоздание массива
	bool GetNextStatus(int i, int j);//статус клетки на след уровне(если 2 или три живые рядом то она живая)
	bool GetNeighbourStatus(int i, int j, int k);//стаутс соседа под номером "k" с данной
	int GetAliveNeighbourCount(int i, int j);//получить кол-во живых соседей
public:
	virtual  void NextGeneration();//чтобы смогли переопределить
	property int Cols//можем получить и мзменить количество клеток по столбцам 
	{
		int get()//получить
		{
			return cols;
		}
		void set(int value)//задать
		{
			SetSize(rows, value);
		}
	}
	property int Rows//можем получить и мзменить количество клеток по строкам
	{
		int get()//получить
		{
			return rows;
		}
		void set(int value)//задать
		{
			SetSize(value, cols);
		}
	}
	property bool Field[int, int]
	{
		bool get(int i, int j)//получаем статус клетки
		{
			if (i >= 0 && j >= 0 && i < rows && j < cols)
			{
				return field[i, j];
			}
			return false;
		}
		void set(int i, int j, bool v)//задаем статут
		{
			if (i >= 0 && j >= 0 && i < rows && j < cols)
			{
				field[i, j] = v;
			}
		}
	}
		property bool NextField[int, int]
	{
		bool get(int i, int j)//получаем статус клетки
		{
			if (i >= 0 && j >= 0 && i < rows && j < cols)
			{
				return GetNextStatus(i, j);
			}
			return false;
		} 
	}
	GameModel();//конструктор без параметров
	GameModel(int rows, int cols);//конструктор с параметрами
	void SetSize(int rows, int cols);//задать размер
};

