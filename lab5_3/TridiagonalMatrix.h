#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

class TridiagonalMatrix {
private:
    int size;  // Размер матрицы
    std::vector<double> diagonal;   // Главная диагональ
    std::vector<double> upper;      // Верхняя диагональ
    std::vector<double> lower;      // Нижняя диагональ

public:
    // Конструктор
    TridiagonalMatrix(int size);

    // Метод для ввода данных
    void input();
    void input(int size);

    // Метод для печати матрицы
    void print() const;

    // Метод для получения следа матрицы
    double tr() const;

    // Метод для вычисления определителя
    double det() const;

    // Операции перегрузки операторов
    friend std::istream& operator>>(std::istream& in, TridiagonalMatrix& m);
    friend std::ostream& operator<<(std::ostream& out, const TridiagonalMatrix& m);

    // Операторы для матриц
    TridiagonalMatrix operator+(const TridiagonalMatrix& m) const;
    TridiagonalMatrix operator-(const TridiagonalMatrix& m) const;
    TridiagonalMatrix operator-() const;
    TridiagonalMatrix operator*(const TridiagonalMatrix& m) const;
    TridiagonalMatrix operator*(double scalar) const;
    TridiagonalMatrix& operator+=(const TridiagonalMatrix& m);
    TridiagonalMatrix& operator-=(const TridiagonalMatrix& m);
};
