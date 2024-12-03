#include <conio.h>
#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

/*
int _getch(); - функция ждёт нажатия любой клавиши и возвращает её виртуальный код.
Для использования функции требуется библиотека conio.h
Виртуальные коды клавиш https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731%28v=vs.85%29.aspx

int _putch(int c); - функция выводит символ в консоль
*/


// Функция при вводе с клавиатуры текста заменяет цифры пробелами
void ReplaceDigit()
{
	int symbol;
	do{
		symbol = _getch();
		if (symbol == VK_RETURN) // Enter
			symbol = '\n';
		if (symbol == VK_ESCAPE) // Escape
			break;
		symbol >= '0' && symbol <= '9' ? _putch(' ') : _putch(symbol);
	} while (true); 
}

// Функция выполняет фильтрацию букв
void Filter()
{
	int symbol;
	do{
		symbol = _getch();
		if (symbol == VK_RETURN) // Enter
			symbol = '\n';
		if (symbol == VK_ESCAPE) // Escape
			break;
		if (symbol >= 'A' && symbol <= 'Z' || symbol >= 'a' && symbol <= 'z')
			continue;
		 _putch(symbol);
	} while (true); 
}

// Функция инициализирует двумерный массив
void Init(int arr[][4], int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 4; j++)
			arr[i][j] = rand() % 100;
	}
}

// Функция печатает двумерный массив
void Print(int arr[][4], int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << setw(4) << arr[i][j];
		cout << endl;
	}
}

// Функция реализует линейный поиск заданного ключа в двумерном массиве
int LinearSearch(int arr[][4], int row, int key)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < 4; j++)
		if (arr[i][j] == key)
			return i * 4 + j;
	}
	return -1;
}

// Функция реализует бинарный поиск заданного ключа в двумерном массиве
int BinarySearch(int arr[][4], int row, int key)
{
	int left = 0, right = row * 4 - 1, index;
	while (left <= right)
	{
		index = (left + right) / 2;
		if (arr[index / 4][index % 4] == key)
			return index;
		else if (arr[index / 4][index % 4] > key)
			right = index - 1;
		else
			left = index + 1;
	}
	return -1;
}

// Функция сортировки массива
void Sort(int arr[][4], int row)
{
	for (int i = 1; i < row * 4; i++)
	{
		int temp = arr[i / 4][i % 4];
		int j = i - 1;
		while (j >= 0 && arr[j / 4][j % 4] > temp)
		{
			arr[(j + 1) / 4][(j + 1) % 4] = arr[j / 4][j % 4];
			j--;
		}
		arr[(j + 1) / 4][(j + 1) % 4] = temp;
	}
}

// Функция инициализирует одномерный массив
void Init(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}

// Функция печатает одномерный массив
void Print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(4) << arr[i];
	}
}

// Сортировка одномерного массива
void Sort(int arr[], int size, bool flag)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (!flag && arr[j - 1] > arr[j] || flag && arr[j - 1] < arr[j])
			{
				int x = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = x;
			}
		}
	}
}