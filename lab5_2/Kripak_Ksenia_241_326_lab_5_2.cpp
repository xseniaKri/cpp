#include "matr.h"
#include "matr.cpp"
#include <iostream>
using namespace std;

int main() {
    // Тестирование конструктора с инициализацией нулями
    cout << "Matrix initialized with zeros (3x3):" << endl;
    Matrix mat1(3, 3);
    mat1.print();

    // Тестирование конструктора с инициализацией заданным массивом
    double arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "\nMatrix initialized with given array (3x3):" << endl;
    Matrix mat2(3, 3, arr1);
    mat2.print();

    // Тестирование метода ввода элементов с клавиатуры
    cout << "\nInput matrix elements manually (2x2):" << endl;
    Matrix mat3(2, 2);
    mat3.input(2, 2);
    mat3.print();

    // Тестирование метода сложения матрицы с массивом (результат записывается в текущую матрицу)
    double arr2[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    cout << "\nAdding array to mat2 and updating mat2 (3x3):" << endl;
    mat2.sum(arr2);
    mat2.print();

    // Тестирование метода сложения матрицы с массивом (возвращает новый объект)
    double arr3[] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    cout << "\nAdding array to mat2 and returning a new matrix:" << endl;
    Matrix* sum_result = mat2.sum(arr3, 9);
    if (sum_result) {
        sum_result->print();
        delete sum_result; // Освобождаем память
    }

    // Тестирование метода умножения матрицы на массив (результат записывается в текущую матрицу)
    double arr4[] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    cout << "\nMultiplying mat2 by array and updating mat2 (3x3):" << endl;
    mat2.mult(arr4);
    mat2.print();

    // Тестирование метода умножения матрицы на массив (возвращает новый объект)
    double arr5[] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5};
    cout << "\nMultiplying mat2 by array and returning a new matrix:" << endl;
    Matrix* mult_result = mat2.mult(arr5, 9);
    if (mult_result) {
        mult_result->print();
        delete mult_result; // Освобождаем память
    }

    return 0;
}