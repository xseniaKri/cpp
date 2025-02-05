#include <iostream>
#include "Position.h"
#include "Circle.h"
#include "Square.h"
#include "CircleInSquare.h"

int main() {
    // Тестирование Position
    Position p1(10, 20);
    std::cout << "Position 1: ";
    p1.print();
    p1.move(5, -5); // Изменяем положение
    std::cout << "After moving Position 1: ";
    p1.print();

    // Тестирование Circle
    Circle c1(0, 0, 5);
    std::cout << "\nCircle 1: ";
    c1.print();
    std::cout << "Area of Circle 1: " << c1.area() << "\n";
    std::cout << "Perimeter of Circle 1: " << c1.perimeter() << "\n";
    c1.setRadius(7); // Изменяем радиус
    std::cout << "After changing radius of Circle 1: ";
    c1.print();

    // Тестирование Square
    Square s1(0, 0, 4);
    std::cout << "\nSquare 1: ";
    s1.print();
    std::cout << "Area of Square 1: " << s1.area() << "\n";
    std::cout << "Perimeter of Square 1: " << s1.perimeter() << "\n";
    s1.setSideLength(6); // Изменяем длину стороны
    std::cout << "After changing side length of Square 1: ";
    s1.print();

    // Тестирование CircleInSquare
    CircleInSquare cns1(0, 0, 5, 10);
    std::cout << "\nCircleInSquare 1: ";
    cns1.print();
    
    // Изменение положения CircleInSquare
    cns1.move(3, 3);
    std::cout << "After moving CircleInSquare 1: ";
    cns1.print();

    return 0;
}
