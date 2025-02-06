#include "myStack.h"
#include <iostream>
#include <string>
using namespace std;

// Проверяем, является ли символ открывающей скобкой
bool open_bracket(char target) {
    return (target == '{' || target == '[' || target == '(');
}

// Проверяем, является ли символ закрывающей скобкой
bool close_bracket(char target) {
    return (target == '}' || target == ']' || target == ')');
}

// Проверяем строку на правильность скобок
bool check(string line) {
    myStack stack;

    for (int i = 0; i < line.length(); i++) {
        char temp = line[i];

        if (open_bracket(temp)) {
            stack.push(temp);
        } 
        else if (close_bracket(temp)) {
            if (stack.is_empty()) {
                return false;  // Если закрывающая скобка без открывающей — ошибка
            }

            char topChar = stack.top();  // Сохраняем верхний элемент перед проверкой
            
            if ((temp == '}' && topChar == '{') ||
                (temp == ']' && topChar == '[') ||
                (temp == ')' && topChar == '(')) {
                stack.pop();  // Удаляем верхний элемент, так как он образует пару
            } else {
                return false;  // Если скобки не совпадают — ошибка
            }
        }
    }

    return stack.is_empty();  // Если стек пуст — правильная последовательность
}

int main() {
    int choice = 1;
    while (choice != 2) {
        cout << "2 - last test, another int - test. enter:  " << endl;
        cin >> choice;
        cout << "Enter your expression: ";
        string check_line;
        cin >> check_line;

        if (check(check_line)) {
            cout << "Right!" << endl;
        } else {
            cout << "Wrong!" << endl;
        }

    }
    

    return 0;
}