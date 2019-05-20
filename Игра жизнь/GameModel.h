#pragma once

ref class GameModel
{
	int cols, rows;//���������� ������ �� �������� � �������
	array <bool, 2> ^field;//������ �������� ������
	
	void RecreateArray();//������������ �������
	bool GetNextStatus(int i, int j);//������ ������ �� ���� ������(���� 2 ��� ��� ����� ����� �� ��� �����)
	bool GetNeighbourStatus(int i, int j, int k);//������ ������ ��� ������� "k" � ������
	int GetAliveNeighbourCount(int i, int j);//�������� ���-�� ����� �������
public:
	virtual  void NextGeneration();//����� ������ ��������������
	property int Cols//����� �������� � �������� ���������� ������ �� �������� 
	{
		int get()//��������
		{
			return cols;
		}
		void set(int value)//������
		{
			SetSize(rows, value);
		}
	}
	property int Rows//����� �������� � �������� ���������� ������ �� �������
	{
		int get()//��������
		{
			return rows;
		}
		void set(int value)//������
		{
			SetSize(value, cols);
		}
	}
	property bool Field[int, int]
	{
		bool get(int i, int j)//�������� ������ ������
		{
			if (i >= 0 && j >= 0 && i < rows && j < cols)
			{
				return field[i, j];
			}
			return false;
		}
		void set(int i, int j, bool v)//������ ������
		{
			if (i >= 0 && j >= 0 && i < rows && j < cols)
			{
				field[i, j] = v;
			}
		}
	}
		property bool NextField[int, int]
	{
		bool get(int i, int j)//�������� ������ ������
		{
			if (i >= 0 && j >= 0 && i < rows && j < cols)
			{
				return GetNextStatus(i, j);
			}
			return false;
		} 
	}
	GameModel();//����������� ��� ����������
	GameModel(int rows, int cols);//����������� � �����������
	void SetSize(int rows, int cols);//������ ������
};

