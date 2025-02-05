#pragma once
#include "Circle.h"
#include "Square.h"

class CircleInSquare : public Circle, public Square {
public:
    CircleInSquare(double x = 0, double y = 0, double radius = 1, double sideLength = 1)
        : Position(x, y), Circle(x, y, radius), Square(x, y, sideLength) {}

    void move(double dx, double dy) override { // Переопределение move
        // Перемещаем и окружность, и квадрат
        Circle::move(dx, dy);
        Square::move(dx, dy);
    }

    void print() const override { // Переопределение print
        Circle::print(); // Печать для окружности
        Square::print(); // Печать для квадрата
    }
};