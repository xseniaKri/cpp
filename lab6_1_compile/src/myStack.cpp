#include <iostream>
#include "myStack.h"
#include <string>
using namespace std;

Node::Node(char value) {
    data = value;
    next = nullptr;
}
myStack::myStack() {
    root = nullptr;
 }

myStack::~myStack(){
    while (!is_empty()) {
        pop();
    }
 }

void myStack::push(char value) {
    Node* newNode = new Node(value);
    newNode->next = root;
    root = newNode;
}

char myStack::pop() {
    if (is_empty()) {
        cout << "Stack is empty" << endl;
        return '\0';
    }
    char root_value = root->data;
    Node* temp = root;
    root = root->next;
    delete temp;
    return root_value;
}

char myStack::top() {
    if (is_empty()) {
        cout << "Stack is empty" << endl;
        return '\0';
    }
    return root->data;
}

bool myStack::is_empty() {
    return root == nullptr;
}

void myStack::clear() {
    while (!is_empty()) {
        pop();
    }
}
