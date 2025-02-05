#pragma once
#include "Position.h"
#include <cmath>
#include <iostream>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Circle : virtual public Position {
protected:
    double radius;

public:
    Circle(double x = 0, double y = 0, double radius = 1) : Position(x, y), radius(radius) {}

    double area() const {
        return M_PI * radius * radius;
    }

    double perimeter() const {
        return 2 * M_PI * radius;
    }

    void setRadius(double newRadius) {
        radius = newRadius;
    }

    void move(double dx, double dy) override { // Переопределение move
        Position::move(dx, dy); // Вызов родительского метода для перемещения
    }

    void print() const override { // Переопределение print
        Position::print(); // Вызов родительского метода для печати
        std::cout << "Circle radius: " << radius << "\n";
    }
};
