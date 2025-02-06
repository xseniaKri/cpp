#include "myStack.h"
#include <iostream>
#include <string>
using namespace std;

//проверяем что перед нами открывающая скобка
bool open_bracket(char target) {
    return (target == '{' || target == '[' || target == '(');
}

//проверяем что перед нами закрывающая скобка
bool close_bracket(char target) {
    return (target == '}' || target == ']' || target == ')');
}

//проверяем строку
bool check(string line) {
    myStack stack;

    for (int i = 0; i < line.length(); i++) {
        char temp = line[i];

        if (open_bracket(temp)) {
            stack.push(temp);
        } 
        else if (close_bracket(temp)) {
            if (stack.is_empty()) {
                return false;
            }

            char topChar = stack.top();
            
            if ((temp == '}' && topChar == '{') ||
                (temp == ']' && topChar == '[') ||
                (temp == ')' && topChar == '(')) {
                stack.pop();  
            } else {
                return false; 
            }
        }
    }

    return stack.is_empty(); 
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