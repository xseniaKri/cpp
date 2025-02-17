#pragma once

struct Node {
    char data;
    Node* next;

    Node(char value);
};

class myStack {
    private:
        int size;
        Node* root;
    
    public:
        myStack();
        ~myStack();
        
        void push(char value);
        char pop();
        char top();
        bool is_empty();
        void clear();
};

    