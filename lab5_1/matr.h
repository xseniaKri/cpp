
#pragma once
class Matrix{
private:
    int rows; // количество строк
    int columns; // количество столбцов
    double* data; // указатель на двумерный динамический массив для хранения элементов
    double determinant(double* arr, int n);
public:
    // Конструкторы и деструктор
    Matrix(int rows, int columns);
    ~Matrix();

    // Методы класса
    Matrix* sum(const Matrix* mat2);
    Matrix* mult(const Matrix* mat2);
    double trace();
    double det();
    Matrix* mult_by_num(double num);
    void input();
    void print() const;
    int get_columns() const;
    int get_rows() const;
    double get_elem(int i, int j) const;
    bool true_index(int i, int j) const;
};