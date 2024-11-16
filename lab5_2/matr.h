#pragma once
class Matrix {
private:
    int rows; // количество строк
    int columns; // количество столбцов
    double* data; // указатель на двумерный динамический массив для хранения элементов

public:
    // Конструкторы и деструктор
    Matrix(int rows, int columns); // инициализация нулями
    Matrix(int rows, int columns, const double* arr); // инициализация заданным массивом
    ~Matrix();

    // Методы класса
    Matrix* sum(const double* arr, int size); // сложение с массивом, возвращает рез
    void sum(const double* arr); // сложение с массивом, запись в текущую матрицу
    Matrix* mult(const double* arr, int size); // умножение на массив, возвращает рез
    void mult(const double* arr); // умножение на массив, запись в текущую матрицу

    void input(int rows, int columns); // ввод элементов матрицы с клавиатуры
    void input(int rows, int columns, double* arr); // инициализация матрицы заданным массивом

    void print() const;
};