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


void shiftRows(int** array, int rows, int cols, int shifts, bool left) {
	int* temp = new int[cols];
	shifts = shifts % cols;

	for (int i = 0; i < rows; ++i) {
		if (left) {
			for (int j = 0; j < shifts; ++j) {
				temp[j] = array[i][j];
			}
			for (int j = shifts; j < cols; ++j) {
				array[i][j - shifts] = array[i][j];
			}
			for (int j = 0; j < shifts; ++j) {
				array[i][cols - shifts + j] = temp[j];
			}
		}
		else {
			for (int j = 0; j < shifts; ++j) {
				temp[j] = array[i][cols - shifts + j];
			}
			for (int j = cols - 1; j >= shifts; --j) {
				array[i][j] = array[i][j - shifts];
			}
			for (int j = 0; j < shifts; ++j) {
				array[i][j] = temp[j];
			}
		}
	}

	delete[] temp;
}

void shiftColumns(int** array, int rows, int cols, int shifts, bool up) {
	int* temp = new int[rows];
	shifts = shifts % rows;

	for (int j = 0; j < cols; ++j) {
		if (up) {
			for (int i = 0; i < shifts; ++i) {
				temp[i] = array[i][j];
			}
			for (int i = shifts; i < rows; ++i) {
				array[i - shifts][j] = array[i][j];
			}
			for (int i = 0; i < shifts; ++i) {
				array[rows - shifts + i][j] = temp[i];
			}
		}
		else {
			for (int i = 0; i < shifts; ++i) {
				temp[i] = array[rows - shifts + i][j];
			}
			for (int i = rows - 1; i >= shifts; --i) {
				array[i][j] = array[i - shifts][j];
			}
			for (int i = 0; i < shifts; ++i) {
				array[i][j] = temp[i];
			}
		}
	}

	delete[] temp;
}

void freeArray(int** array, int rows, int cols) {
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

	int shifts;
	cout << "Enter number of shifts:" << endl;
	cin >> shifts;

	char type;
	cout << "Rows(r) or Columns(c)? ";
	cin >> type;

	bool left = false, up = false;

	if (type == 'r') {
		char direction;
		cout << "Left (l) or Right (r)? ";
		cin >> direction;
		left = (direction == 'l');
		shiftRows(array, rows, cols, shifts, left);
	}
	else if (type == 'c') {
		char direction;
		cout << "Up (u) or Down (d)? ";
		cin >> direction;
		up = (direction == 'u');
		shiftColumns(array, rows, cols, shifts, up);
	}
	else {
		cout << "Wrong choice" << endl;
	}

	printArray(array, rows, cols);

	freeArray(array, rows, cols);

	return 0;
}