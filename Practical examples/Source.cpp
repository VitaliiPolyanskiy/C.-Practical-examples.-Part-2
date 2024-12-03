#include <iostream>
#include <ctime>
#include "Library.h"
using namespace std;

int main()
{
	system("cls");
	cout << "Enter a text: \n";
	ReplaceDigit();

	system("cls");
	cout << "Enter a text: \n";
	Filter();

	system("pause");
	system("cls");
	srand(time(0));
	const int ROW = 3, COLUMN = 4;
	int arr[ROW][COLUMN], key;
	Init(arr, ROW);
	Print(arr, ROW);

	cout << "\nEnter a key: ";
	cin >> key;
	int position = LinearSearch(arr, ROW, key);
	if (position == -1)
		cout << "Key was not found" << "\n\n";
	else
		cout << "Key was found in position (" << position / COLUMN << ", " << position % COLUMN << ")" << "\n\n";


	Sort(arr, ROW);
	Print(arr, ROW);
	cout << "\nEnter a key ";
	cin >> key;
	position = BinarySearch(arr, ROW, key);
	if (position == -1)
		cout << "Key was not found" << "\n\n";
	else
		cout << "Key was found in position (" << position / COLUMN << ", " << position % COLUMN << ")" << "\n\n";

	const int SIZE = 10;
	int ar[SIZE];
	Init(ar, SIZE);
	cout << "\nUnsorted array:\n";
	Print(ar, SIZE);

	Sort(ar, SIZE, true);
	cout << "\nArray sorted in descending order:\n";
	Print(ar, SIZE);
	Sort(ar, SIZE);
	cout << "\nArray is sorted in ascending:\n";
	Print(ar, SIZE);

	return 0;
}