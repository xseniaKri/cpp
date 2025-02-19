#pragma once

#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node (int value);
};

class myQueue {
    private:
        int length;
        Node* front;
        Node* back;
    public:
        myQueue();
        ~myQueue();

        void enqueue(int value);
        int dequeue();
        int get_top();
        bool is_empty();
        int getsize();
};