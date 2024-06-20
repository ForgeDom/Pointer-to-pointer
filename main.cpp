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


void removeRow(int**& array, int& rows, int cols, int position) {
    if (position < 0 || position >= rows) {
        cout << "Wrong line" << endl;
        return;
    }

    int** newArray = new int* [rows - 1];

    for (int i = 0, j = 0; i < rows; ++i) {
        if (i != position) {
            newArray[j++] = array[i];
        }
        else {
            delete[] array[i];
        }
    }

    delete[] array;
    array = newArray;
    rows--;
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

    int rows = 5;
    int cols = 3;

    int** array = createArray(rows, cols);

    printArray(array, rows, cols);

    int newRow[] = { 7, 8, 9 };
    int position;
    cout << "Enter line:" << endl;
    cin >> position;
    removeRow(array, rows, cols, position);
        printArray(array, rows, cols);

    freeArray(array, rows);

    return 0;
}
