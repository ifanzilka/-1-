#include "GameModel.h"

void GameModel::RecreateArray()
{
	field = gcnew array <bool, 2>(rows,cols);
}
bool GameModel::GetNextStatus(int i, int j) // статус клетки на след уровне
{
	int nc = GetAliveNeighbourCount(i, j);
	if (Field[i, j]) {
		return nc == 2 || nc == 3;
	}
	return nc == 3;
}
bool GameModel::GetNeighbourStatus(int i, int j, int k) // статутс соседа К
{
	int pi = ((i - 1) >= 0) ? i - 1 : (rows - 1);
	int ni = ((i + 1) < (rows)) ? (i + 1) : 0;
	int pj = ((j - 1) >= 0) ? j - 1 : (cols - 1);
	int nj = ((j + 1) < (cols)) ? (j + 1) : 0;
	switch (k)
	{
	case 0: return Field[pi, pj];
	case 1: return Field[pi, j];
	case 2: return Field[pi, nj];
	case 3: return Field[i, pj];
	case 4: return Field[i, nj];
	case 5: return Field[ni, pj];
	case 6: return Field[ni, j];
	case 7: return Field[ni, nj];
	default: return false;
	}
}
int GameModel::GetAliveNeighbourCount(int i, int j) //кол во живых соседей
{

	int cnt = 0;
	for (int k = 0; k < 8; k++)
	{
		if (GetNeighbourStatus(i, j, k)) cnt++;
	}
	return cnt;

}

void GameModel::NextGeneration()
{
	array<bool, 2>^ newGen =
		gcnew array<bool, 2>(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			newGen[i, j] = GetNextStatus(i, j);
		}
	}
	field = newGen;
}

GameModel::GameModel()
{
	SetSize(20, 20);
}
GameModel::GameModel(int rows, int cols) 
{
	SetSize(rows, cols);
}
void GameModel::SetSize(int rows,int cols)
{
	bool changed = false;
	if (rows < 10) rows = 10;
	else if (rows > 100) rows = 100;
	if (rows != this->rows) {
		changed = true;
		this->rows = rows;
	}
	if (cols < 10) cols = 10;
	else if (cols > 100) cols = 100;
	if (cols != this->cols) {
		changed = true;
		this->cols = cols;
	}
	if (changed) RecreateArray();
}

