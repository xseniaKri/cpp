#include "myStack.h"
#include <iostream>
using namespace std;

//проверяем что перед нами открывающая скобка
bool open_bracket(char target) {
    char arr[] = {'{', '(', '['};
    int i = 0;
    while (i < 3) {
        if (target == arr[i]) {
            cout << "Found it!";
            return true;
            break;
        }
        i++;
    }
    return false;
}

//проверяем что перед нами закрывающая скобка
bool close_bracket(char target) {
    char arr[] = {'}', ')', ']'};
    int i = 0;
    while (i < 3) {
        if (target == arr[i]) {
            return true;
            break;
        }
        i++;
    }
    return false;
}

//проверяем строку
bool check() {
    char temp = '\0';
    myStack stack;
    while (temp != '\r') {
        cin >> temp;
        cout << "a";
        if (open_bracket(temp)) {
            stack.push(temp);
        }
        if (close_bracket(temp)) {
            if ((temp - stack.top() == 1) || (temp - stack.top() == 2)) {
                char d = stack.pop();
                continue;
            }
            else {
                return false;
            }
        }

    }
    if (stack.is_empty()) {
        return true;
    }
    else return false;
}

int main() {
    cout << "Enter your expression" << endl;
    if (check()) {
        cout << "Right!" << endl;
    }
    else cout << "Wrong!" << endl;
    return 0;
}