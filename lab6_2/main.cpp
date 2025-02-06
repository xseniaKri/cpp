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
    int i = 0;
    for (i = 0; i < line.length(); i++) {
        char temp = line[i];
        if (open_bracket(temp)) {
            stack.push(temp);
        }
        if (close_bracket(temp)) {
            if (stack.is_empty()) {
                return false;
            }
            if ((temp == '}' && stack.top() == '{')
            || (temp == ']' && stack.top() == '[')
            || (temp == ')' && stack.top() == '(')) {
            char d = stack.pop();
        }
            }
            else {
                return false;
            }
        }
    return stack.is_empty();
}

int main() {
    cout << "Enter your expression" << endl;
    string check_line;
    cin.clear();
    cin.sync();
    getline(cin, check_line);
    if (check(check_line)) {
        cout << "Right!" << endl;
    }
    else cout << "Wrong!" << endl;
    return 0;
}