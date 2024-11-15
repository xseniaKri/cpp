#include "matr.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// Конструктор: инициализация матрицы заданного размера
Matrix::Matrix(int rows, int columns) {
    this->rows = rows; 
    this->columns = columns; 
    data = new double[rows * columns]();
}

// Деструктор: освобождение памяти
Matrix::~Matrix() {
    delete[] data;
}

// Получение количества строк и столбцов
int Matrix::get_rows() const {
    return rows;
}
int Matrix::get_columns() const {
    return columns;
}
// Проверка индекса элемента
bool Matrix::true_index(int i, int j) const {
    if (i >= rows || j >= columns) {
        return false;
    }
    else return true;
} 
// Получение элемента матрицы
double Matrix::get_elem(int i, int j) const {
    if (! true_index(i, j)) {
        cout << "Index out of range";
    }
    else return data[i * columns + j];
}
// Ввод элементов матрицы с клавиатуры
void Matrix::input() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> data[i * columns + j];
        }
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

// Сложение матриц
Matrix* Matrix::sum(const Matrix* mat2) {
    if (rows != mat2->rows || columns != mat2->columns) {
        cout << "Matrices must be of the same size for addition";
    }
    else {
        Matrix* result = new Matrix(rows, columns);
        for (int i = 0; i < rows * columns; i++) {
            result->data[i] = data[i] + mat2->data[i];
        }
        return result;
    }
}

// Умножение матриц
Matrix* Matrix::mult(const Matrix* mat2) {
    if (columns != mat2->rows) {
        cout << "Number of columns of the first matrix must match the number of rows of the second matrix";
    }
    else {
        Matrix* result = new Matrix(rows, mat2->columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < mat2->columns; j++) {
                result->data[i * mat2->columns + j] = 0;
                for (int k = 0; k < columns; k++) {
                    result->data[i * mat2->columns + j] += data[i * columns + k] * mat2->data[k * mat2->columns + j];
                }
            }
        }
        return result;
    }
}

// Умножение матрицы на число
Matrix* Matrix::mult_by_num(double num) {
    Matrix* result = new Matrix(rows, columns);
    for (int i = 0; i < rows * columns; i++) {
        result->data[i] = data[i] * num;
    }
    return result;
}

// След матрицы (сумма элементов на главной диагонали)
double Matrix::trace() {
    if (rows != columns) {
        cout << "Matrix must be square to calculate the trace";
    }
    else {
        double trace_sum = 0;
        for (int i = 0; i < rows; i++) {
            trace_sum += data[i * columns + i];
        }
        return trace_sum;
    }
}

// Определитель матрицы (рекурсивный метод)
double Matrix::det() {
    if (rows != columns) {
        cout << "The determinant can only be calculated for a square matrix";
    }
    else return determinant(data, rows);
}

double Matrix::determinant(double* arr, int n) {
    if (n == 1) return arr[0];
    if (n == 2) return arr[0] * arr[3] - arr[1] * arr[2];

    double det = 0;
    double* submatrix = new double[(n - 1) * (n - 1)];
    for (int x = 0; x < n; x++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x) continue;
                submatrix[subi * (n - 1) + subj] = arr[i * n + j];
                subj++;
            }
            subi++;
        }
        det += (x % 2 == 0 ? 1 : -1) * arr[x] * determinant(submatrix, n - 1);
    }
    delete[] submatrix;
    return det;
}