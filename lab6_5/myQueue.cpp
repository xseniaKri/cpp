#include <iostream>
#include "myQueue.h"
#include <string>
using namespace std;

Node::Node(int value) {
    prev = nullptr;
    data = value;
}

myQueue::myQueue() {
    length = 0;
    front = nullptr;
    back = nullptr;
}

myQueue::~myQueue() {
    while (!is_empty()) {
        Node* temp = front;
        front = front->prev;
        delete temp;
        length--;
    }
}

void myQueue::enqueue(int value) {
    Node* newNode = new Node(value);
    if (is_empty()) {
        front = newNode;
        back = newNode;
    }
    else {
        back->prev = newNode;
        back = newNode;
    }
    length++;
}

int myQueue::dequeue() {
    if (is_empty()) {
        cout << "Queue is empty!";
        return -1;
    }
    else {
        Node* temp = front;
        int top_data = temp->data; 
        front = front->prev;
        delete temp;
        length--;
        return top_data;
    }
}

int myQueue::get_top() {
    if (is_empty()) {
        cout << "Queue is empty!";
        return -1;
    }
    else {
        return front->data;
    }
}

bool myQueue::is_empty() {
    return length == 0;
}

int myQueue::getsize() {
    return length;
}