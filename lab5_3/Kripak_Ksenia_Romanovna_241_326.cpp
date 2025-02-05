#include <iostream>
#include "TridiagonalMatrix.h"
#include "TridiagonalMatrix.cpp"

int main() {
    // Тестирование конструктора и ввода матрицы
    TridiagonalMatrix mat1(3); // Создаем матрицу размером 3x3

    // Заполняем матрицу автоматически
    mat1.input(3); 

    // Печатаем матрицу
    std::cout << "Matrix 1 (auto-generated):\n";
    std::cout << mat1 << std::endl;

    // Вводим матрицу с клавиатуры
    TridiagonalMatrix mat2(3);
    mat2.input(); // Ввод данных с клавиатуры

    std::cout << "Matrix 2 (user input):\n";
    std::cout << mat2 << std::endl;

    // Тестирование оператора сложения
    TridiagonalMatrix mat3 = mat1 + mat2;
    std::cout << "Matrix 1 + Matrix 2:\n";
    std::cout << mat3 << std::endl;

    // Тестирование оператора вычитания
    TridiagonalMatrix mat4 = mat1 - mat2;
    std::cout << "Matrix 1 - Matrix 2:\n";
    std::cout << mat4 << std::endl;

    // Тестирование унарного оператора (смена знаков элементов)
    TridiagonalMatrix mat5 = -mat1;
    std::cout << "Negative of Matrix 1:\n";
    std::cout << mat5 << std::endl;

    // Тестирование оператора умножения на число
    TridiagonalMatrix mat6 = mat1 * 2.0;
    std::cout << "Matrix 1 * 2:\n";
    std::cout << mat6 << std::endl;

    // Тестирование оператора умножения матриц
    TridiagonalMatrix mat7 = mat1 * mat2;
    std::cout << "Matrix 1 * Matrix 2 (Matrix multiplication):\n";
    std::cout << mat7 << std::endl;

    // Тестирование оператора +=
    mat1 += mat2;
    std::cout << "Matrix 1 += Matrix 2:\n";
    std::cout << mat1 << std::endl;

    // Тестирование оператора -=
    mat1 -= mat2;
    std::cout << "Matrix 1 -= Matrix 2:\n";
    std::cout << mat1 << std::endl;

    // Тестирование вычисления следа матрицы
    double trace = mat1.tr();
    std::cout << "Trace of Matrix 1: " << trace << std::endl;

    // Тестирование вычисления определителя
    double determinant = mat1.det();
    std::cout << "Determinant of Matrix 1: " << determinant << std::endl;

    return 0;
}
