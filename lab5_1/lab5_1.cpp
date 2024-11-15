#include <iostream>
#include "matr.h"
#include "matr.cpp"
using namespace std;



// Тестирование программы
int main() {
    int rows, columns;
    cout << "Enter the number of rows and columns for the matrix: ";
    cin >> rows >> columns;
    // Ввод матрицы
    Matrix mat1(rows, columns);
    cout << "Enter the elements of your matrix:" << endl;
    mat1.input();
    // Методы get_rows и get_columns
    printf("Size of yout matrix: %d x %d", mat1.get_rows(), mat1.get_columns());
    cout << endl;
    // Вывод матрицы
    cout << "Entered matrix:" << endl;
    mat1.print();
    // Умножение матрицы на число
    Matrix* mat2 = mat1.mult_by_num(3);
    cout << "Matrix multiplied by 3:" << endl;
    mat2->print();
    // Суммирование матриц (в данном случае к матрице прибавляем её же)
    Matrix* mat3 = mat1.sum(&mat1);
    cout << "Matrix multiplied by 2:" << endl;
    mat3->print();
    // След и определитель
    if (rows == columns) {
        cout << "Trace of the matrix: " << mat1.trace() << endl;
        cout << "Determinant of the matrix: " << mat1.det() << endl;
    }
    else cout << "Your matrix isn't square, we can't calculate it's trace and determinant" << endl;
    // Метод get_elem
    cout << "Enter indexes of element: ";
    int i, j;
    cin >> i >> j;
    cout << "Your element: " << mat1.get_elem(i, j);
    delete mat2;
    delete mat3;
    return 0;
}
