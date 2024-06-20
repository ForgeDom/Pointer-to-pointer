#include <iostream>
#include <ctime>
using namespace std;

int** createArray(int rows, int cols) {
	int** array = new int* [rows];
	for (int i = 0; i < rows; ++i) {
		array[i] = new int[cols];
		for (int j = 0; j < cols; ++j) {
			array[i][j] = rand() % 10;
		}
	}
	return array;
}

void removeColumn(int**& array, int rows, int& cols, int position) {
	if (position < 0 || position > cols) {
		cout << "Wrong line" << endl;
		return;
	}

	for (int i = 0; i < rows; ++i) {
		int* newRow = new int[cols - 1];
		for (int j = 0, k = 0; j < cols; ++j) {
			if (j != position) {
				newRow[k++] = array[i][j];
			}
		}
		delete[] array[i];
		array[i] = newRow;
	}
	cols--;
}

void freeArray(int** array, int rows) {
	for (int i = 0; i < rows; ++i) {
		delete[] array[i];
	}
	delete[] array;
}

void printArray(int** array, int rows, int cols) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	srand(time(0));

	int rows = 3;
	int cols = 8;

	int** array = createArray(rows, cols);

	printArray(array, rows, cols);

	int position;
	cout << "Enter column: ";
	cin >> position;

	removeColumn(array, rows, cols, position);
	printArray(array, rows, cols);

	freeArray(array, rows);

	return 0;
}