#pragma once
#include <iostream>
class Position {
protected:
    double x, y; // Координаты на экране

public:
    Position(double x = 0, double y = 0) : x(x), y(y) {}

    virtual void move(double dx, double dy) { // Метод для изменения положения
        x += dx;
        y += dy;
    }

    virtual void print() const { // Печать положения
        std::cout << "Position: (" << x << ", " << y << ")\n";
    }

    virtual ~Position() {} // Виртуальный деструктор для безопасного уничтожения
};
