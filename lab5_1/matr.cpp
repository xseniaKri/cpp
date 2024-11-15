#include "matr.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// Конструктор: инициализация матрицы заданного размера
Matrix::Matrix(int rows, int columns) : rows(rows), columns(columns) {
    // Выделение памяти для двумерного массива
    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[columns]();
    }
}

// Деструктор: освобождение памяти
Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}

// Получение количества строк и столбцов
int Matrix::get_rows() const {
    return rows; 
}
int Matrix::get_columns() const {
    return columns;
    }

// Получение элемента матрицы
double Matrix::get_elem(int i, int j) const {
    if (i >= rows || j >= columns) cout << "Index out of range" << endl;
    else return data[i][j];
}

// Установка элемента матрицы
void Matrix::set_elem(int i, int j, double value) {
    if (i >= rows || j >= columns) cout << "Index out of range" << endl;
    else data[i][j] = value;
}

// Ввод элементов матрицы с клавиатуры
void Matrix::input() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Enter element [ %d ][ %d ]", i, j);
            //cout << "Введите элемент [" << i << "][" << j << "]: ";
            cin >> data[i][j];
        }
    }
}

// Печать матрицы на экран
void Matrix::print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

// Сложение матриц
Matrix* Matrix::sum(const Matrix* mat2) {
    if (rows != mat2->rows || columns != mat2->columns) //используем -> тк передали указатель на объект
        cout << "For addition, the matrices must be of the same size";

    Matrix* result = new Matrix(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result->data[i][j] = data[i][j] + mat2->data[i][j];
        }
    }
    return result;
}

// Умножение матриц
Matrix* Matrix::mult(const Matrix* mat2) {
    if (columns != mat2->rows)
        cout << "The number of columns of the first matrix must be equal to the number of rows of the second matrix";

    Matrix* result = new Matrix(rows, mat2->columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < mat2->columns; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < columns; k++) {
                result->data[i][j] += data[i][k] * mat2->data[k][j];
            }
        }
    }
    return result;
}

// Умножение матрицы на число
Matrix* Matrix::mult_by_num(double num) {
    Matrix* result = new Matrix(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result->data[i][j] = data[i][j] * num;
        }
    }
    return result;
}

// След матрицы (сумма элементов на главной диагонали)
double Matrix::trace() {
    if (rows != columns)
        cout << "Matrix must be square to calculate the trace";

    double trace_sum = 0;
    for (int i = 0; i < rows; i++) {
        trace_sum += data[i][i];
    }
    return trace_sum;
}

// Определитель матрицы (рекурсивный метод)
double Matrix::det() {
    if (rows != columns)
        cout << "The determinant can only be calculated for a square matrix";

    return determinant(data, rows);
}

double Matrix::determinant(double** arr, int n) {
    if (n == 1) return arr[0][0];
    if (n == 2) return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
// При n >= 3 используем разложение по 1-й строке
    double det = 0;
    double** submatrix = new double*[n - 1];
    for (int i = 0; i < n - 1; i++) {
        submatrix[i] = new double[n - 1];
    }

    for (int x = 0; x < n; x++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x) continue;
                submatrix[subi][subj++] = arr[i][j];
            }
            subi++;
        }
        det += (x % 2 == 0 ? 1 : -1) * arr[0][x] * determinant(submatrix, n - 1);
    }

    for (int i = 0; i < n - 1; i++) {
        delete[] submatrix[i];
    }
    delete[] submatrix;
    return det;
}