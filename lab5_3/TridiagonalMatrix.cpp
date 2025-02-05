#include "TridiagonalMatrix.h"

// Конструктор
TridiagonalMatrix::TridiagonalMatrix(int size) : size(size) {
    diagonal.resize(size);
    upper.resize(size - 1);
    lower.resize(size - 1);
}

// Метод для ввода данных
void TridiagonalMatrix::input() {
    std::cout << "Enter size of the matrix: ";
    std::cin >> size;

    diagonal.resize(size);
    upper.resize(size - 1);
    lower.resize(size - 1);

    for (int i = 0; i < size; i++) {
        std::cout << "Enter element for diagonal[" << i << "]: ";
        std::cin >> diagonal[i];
    }

    for (int i = 0; i < size - 1; i++) {
        std::cout << "Enter element for upper[" << i << "]: ";
        std::cin >> upper[i];
        std::cout << "Enter element for lower[" << i << "]: ";
        std::cin >> lower[i];
    }
}

// Метод для автоматического заполнения матрицы
void TridiagonalMatrix::input(int size) {
    this->size = size;
    diagonal.resize(size);
    upper.resize(size - 1);
    lower.resize(size - 1);

    for (int i = 0; i < size; i++) {
        diagonal[i] = i + 1;
    }

    for (int i = 0; i < size - 1; i++) {
        upper[i] = i + 2;
        lower[i] = i + 3;
    }
}

// Метод для печати матрицы
void TridiagonalMatrix::print() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                std::cout << diagonal[i] << " ";
            } else if (i == j - 1) {
                std::cout << upper[i] << " ";
            } else if (i == j + 1) {
                std::cout << lower[j] << " ";
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}

// Метод для получения следа матрицы
double TridiagonalMatrix::tr() const {
    double trace = 0;
    for (int i = 0; i < size; i++) {
        trace += diagonal[i];
    }
    return trace;
}

// Метод для вычисления определителя (через рекурсию)
double TridiagonalMatrix::det() const {
    if (size == 1) {
        return diagonal[0];
    }
    if (size == 2) {
        return diagonal[0] * diagonal[1] - lower[0] * upper[0];
    }

    double det_val = diagonal[0];
    double prev_det = 1;
    for (int i = 0; i < size - 1; i++) {
        prev_det = diagonal[i] - lower[i] * upper[i] / prev_det;
    }
    det_val *= prev_det;
    return det_val;
}

// Оператор ввода (работает как input())
std::istream& operator>>(std::istream& in, TridiagonalMatrix& m) {
    m.input();
    return in;
}

// Оператор вывода (работает как print())
std::ostream& operator<<(std::ostream& out, const TridiagonalMatrix& m) {
    m.print();
    return out;
}

// Оператор сложения матриц
TridiagonalMatrix TridiagonalMatrix::operator+(const TridiagonalMatrix& m) const {
    if (this->size != m.size) {
        throw std::invalid_argument("Matrix sizes must match for addition");
    }

    TridiagonalMatrix result(size);

    for (int i = 0; i < size; i++) {
        result.diagonal[i] = this->diagonal[i] + m.diagonal[i];
    }

    for (int i = 0; i < size - 1; i++) {
        result.upper[i] = this->upper[i] + m.upper[i];
        result.lower[i] = this->lower[i] + m.lower[i];
    }

    return result;
}

// Оператор вычитания матриц
TridiagonalMatrix TridiagonalMatrix::operator-(const TridiagonalMatrix& m) const {
    if (this->size != m.size) {
        throw std::invalid_argument("Matrix sizes must match for subtraction");
    }

    TridiagonalMatrix result(size);

    for (int i = 0; i < size; i++) {
        result.diagonal[i] = this->diagonal[i] - m.diagonal[i];
    }

    for (int i = 0; i < size - 1; i++) {
        result.upper[i] = this->upper[i] - m.upper[i];
        result.lower[i] = this->lower[i] - m.lower[i];
    }

    return result;
}

// Унарный оператор (изменение знака всех ненулевых элементов)
TridiagonalMatrix TridiagonalMatrix::operator-() const {
    TridiagonalMatrix result(size);

    for (int i = 0; i < size; i++) {
        result.diagonal[i] = -this->diagonal[i];
    }

    for (int i = 0; i < size - 1; i++) {
        result.upper[i] = -this->upper[i];
        result.lower[i] = -this->lower[i];
    }

    return result;
}

// Оператор умножения матриц
TridiagonalMatrix TridiagonalMatrix::operator*(const TridiagonalMatrix& m) const {
    if (this->size != m.size) {
        throw std::invalid_argument("Matrix sizes must match for multiplication");
    }

    TridiagonalMatrix result(size);

    for (int i = 0; i < size; i++) {
        result.diagonal[i] = this->diagonal[i] * m.diagonal[i];
    }

    for (int i = 0; i < size - 1; i++) {
        result.upper[i] = this->upper[i] * m.upper[i];
        result.lower[i] = this->lower[i] * m.lower[i];
    }

    return result;
}

// Оператор умножения на число
TridiagonalMatrix TridiagonalMatrix::operator*(double scalar) const {
    TridiagonalMatrix result(size);

    for (int i = 0; i < size; i++) {
        result.diagonal[i] = this->diagonal[i] * scalar;
    }

    for (int i = 0; i < size - 1; i++) {
        result.upper[i] = this->upper[i] * scalar;
        result.lower[i] = this->lower[i] * scalar;
    }

    return result;
}

// Оператор +=
TridiagonalMatrix& TridiagonalMatrix::operator+=(const TridiagonalMatrix& m) {
    if (this->size != m.size) {
        throw std::invalid_argument("Matrix sizes must match for addition");
    }

    for (int i = 0; i < size; i++) {
        this->diagonal[i] += m.diagonal[i];
    }

    for (int i = 0; i < size - 1; i++) {
        this->upper[i] += m.upper[i];
        this->lower[i] += m.lower[i];
    }

    return *this;
}

// Оператор -=
TridiagonalMatrix& TridiagonalMatrix::operator-=(const TridiagonalMatrix& m) {
    if (this->size != m.size) {
        throw std::invalid_argument("Matrix sizes must match for subtraction");
    }

    for (int i = 0; i < size; i++) {
        this->diagonal[i] -= m.diagonal[i];
    }

    for (int i = 0; i < size - 1; i++) {
        this->upper[i] -= m.upper[i];
        this->lower[i] -= m.lower[i];
    }

    return *this;
}