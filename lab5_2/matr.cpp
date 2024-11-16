#include "matr.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// Конструктор инициализации нулями
Matrix::Matrix(int rows, int columns) {
    this->rows = rows; 
    this->columns = columns; 
    data = new double[rows * columns]();
}

// Конструктор инициализации заданным массивом
Matrix::Matrix(int rows, int columns, const double* arr) : rows(rows), columns(columns) {
    data = new double[rows * columns];
    for (int i = 0; i < rows * columns; i++) {
        data[i] = arr[i];
    }
}

// Деструктор: освобождение памяти
Matrix::~Matrix() {
    delete[] data;
}

// Ввод элементов матрицы с клавиатуры с заданными размерами
void Matrix::input(int rows, int columns) {
    delete[] data;
    this->rows = rows;
    this->columns = columns;
    data = new double[rows * columns];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> data[i * columns + j];
        }
    }
}

// Инициализация матрицы заданным массивом
void Matrix::input(int rows, int columns, double* arr) {
    delete[] data;
    this->rows = rows;
    this->columns = columns;
    data = new double[rows * columns];
    for (int i = 0; i < rows * columns; i++) {
        data[i] = arr[i];
    }
}


// Печать матрицы на экран
void Matrix::print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << data[i * columns + j] << " ";
        }
        cout << endl;
    }
}

// Сложение текущей матрицы с массивом, возвращает нулевой указатель или результат
Matrix* Matrix::sum(const double* arr, int size) {
    if (size != rows * columns) {
        cout << "Array size does not match matrix size." << endl;
        return nullptr;
    }
    else {
        Matrix* result = new Matrix(rows, columns);
        for (int i = 0; i < rows * columns; i++) {
            result->data[i] = data[i] + arr[i];
        }
        return result;
    }
}

// Сложение текущей матрицы с массивом и запись результата в текущую матрицу
void Matrix::sum(const double* arr) {
    // Проверка на совпадение размеров
    if (arr == nullptr) {
        cout << "Error: Null array pointer." << endl;
        return;
    }

    for (int i = 0; i < rows * columns; i++) {
        data[i] += arr[i];
    }
}


// Умножение матрицы на массив
Matrix* Matrix::mult(const double* arr, int size) {
    if (size != rows * columns) {
        cout << "Array size does not match matrix size." << endl;
        return nullptr;
    }
    else {
        Matrix* result = new Matrix(rows, columns);
        for (int i = 0; i < rows * columns; i++) {
            result->data[i] = data[i] * arr[i];
        }
        return result;
    }
}

// Умножение текущей матрицы на массив и запись результата в текущую матрицу
void Matrix::mult(const double* arr) {
    // Умножение элементов матрицы на элементы массива
    for (int i = 0; i < rows * columns; i++) {
        data[i] *= arr[i];
    }
}
