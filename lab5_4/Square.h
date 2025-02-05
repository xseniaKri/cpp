#pragma once
#include "Position.h"
#include <cmath>
#include <iostream>

class Square : virtual public Position {
protected:
    double sideLength;

public:
    Square(double x = 0, double y = 0, double sideLength = 1) : Position(x, y), sideLength(sideLength) {}

    double area() const {
        return sideLength * sideLength;
    }

    double perimeter() const {
        return 4 * sideLength;
    }

    void setSideLength(double newLength) {
        sideLength = newLength;
    }

    void move(double dx, double dy) override { // Переопределение move
        Position::move(dx, dy); // Вызов родительского метода для перемещения
    }

    void print() const override { // Переопределение print
        Position::print(); // Вызов родительского метода для печати
        std::cout << "Square side length: " << sideLength << "\n";
    }
};
