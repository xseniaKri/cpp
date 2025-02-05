#include <iostream>
#include "myStack.h"
#include "myStack.cpp"
using namespace std;

int main() {
    myStack stack;
    stack.push('A');
    stack.push('B');
    cout << stack.top();
    return 0;
}