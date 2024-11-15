#include <iostream>
#include "matr.h"
#include "matr.cpp"
using namespace std;



// Тестирование программы
int main() {
    int rows, columns;
    cout << "Enter the number of rows and columns for the matrix: ";
    cin >> rows >> columns;

    Matrix mat1(rows, columns);
    cout << "Enter the elements of your matrix:" << endl;
    mat1.input();

    cout << "Entered matrix:" << endl;
    mat1.print();

    Matrix* mat2 = mat1.mult_by_num(2);
    cout << "Matrix multiplied by 2:" << endl;
    mat2->print();

    if (rows == columns) {
        cout << "Trace of the matrix: " << mat1.trace() << endl;
        cout << "Determinant of the matrix: " << mat1.det() << endl;
    }

    delete mat2;
    return 0;
}
