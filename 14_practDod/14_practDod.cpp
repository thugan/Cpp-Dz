#include <iostream>
#include <iomanip>
using namespace std;

void InitArray(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 90 + 10;
		}
	}
}

void ShowArray(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(4) << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----------------------------------" << endl << endl;
}

void FillRow(int* arr, int cols)
{
	for (int i = 0; i < cols; i++)
	{
		arr[i] = rand() % 10;
	}
}

int** AddNewRowStart(int** arr, int& rows, int cols)
{
	int** temp = new int* [rows + 1];
	temp[0] = new int[cols];
	FillRow(temp[0], cols);

	for (int i = 0; i < rows; i++)
	{
		temp[i + 1] = arr[i];
	}

	delete[]arr;
	rows++;
	return temp;
}

int** DelRowStart(int** arr, int& rows, int& cols)
{
	delete[] arr[0];

	int** temp = new int* [rows - 1];

	for (int i = 1; i < rows; i++)
	{
		temp[i - 1] = arr[i];
	}

	delete[] arr;
	rows--;

	return temp;
}

int** DelRowByPosition(int** arr, int& rows, int cols, int pos)
{
	int** temp = new int* [rows - 1];

	delete[] arr[pos];

	for (int i = 0; i < pos; i++)
	{
		temp[i] = arr[i];
	}

	for (int i = pos + 1; i < rows; i++)
	{
		temp[i - 1] = arr[i];
	}

	delete[] arr;
	rows--;

	return temp;
}

int** AddColumnStart(int** arr, int& rows, int& cols)
{
	int** temp = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		temp[i] = new int[cols + 1];
		temp[i][0] = 5;

		for (int j = 0; j < cols; j++)
		{
			temp[i][j + 1] = arr[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

	delete[]arr;
	cols++;

	return temp;
}

int** AddColumnByPosition(int** arr, int rows, int& cols, int pos)
{
	int** temp = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		temp[i] = new int[cols + 1];

		for (int j = 0; j < pos; j++)
		{
			temp[i][j] = arr[i][j];
		}

		temp[i][pos] = 5;

		for (int j = pos; j < cols; j++)
		{
			temp[i][j + 1] = arr[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

	delete[]arr;
	cols++;

	return temp;
}

int** DelColumnByPosition(int** arr, int rows, int& cols, int pos)
{
	int** temp = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		temp[i] = new int[cols - 1];

		for (int j = 0; j < pos; j++)
		{
			temp[i][j] = arr[i][j];
		}

		for (int j = pos + 1; j < cols; j++)
		{
			temp[i][j - 1] = arr[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

	delete[]arr;
	cols--;

	return temp;
}

int main()
{
	int rows = 4;
	int cols = 5;

	int** arr = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	InitArray(arr, rows, cols);
	ShowArray(arr, rows, cols);

	arr = AddNewRowStart(arr, rows, cols);
	ShowArray(arr, rows, cols);

	arr = DelRowStart(arr, rows, cols);
	ShowArray(arr, rows, cols);

	arr = DelRowByPosition(arr, rows, cols, 1);
	ShowArray(arr, rows, cols);

	arr = AddColumnStart(arr, rows, cols);
	ShowArray(arr, rows, cols);

	arr = AddColumnByPosition(arr, rows, cols, 2);
	ShowArray(arr, rows, cols);

	arr = DelColumnByPosition(arr, rows, cols, 1);
	ShowArray(arr, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

	delete[]arr;
}