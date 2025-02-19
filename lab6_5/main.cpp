#include <iostream>
#include "myQueue.h"
#include "myQueue.cpp"
#include <string>
using namespace std;

int main() {
    myQueue newQ;
    newQ.enqueue(4);
    newQ.enqueue(7);
    newQ.enqueue(6);
    cout << newQ.getsize() << " - size " << newQ.get_top() << " - top element" << endl;
    int p = newQ.dequeue(); 
    cout << "deleted el: " << p << endl << "now top el: " << newQ.get_top() << endl << "now size: " << newQ.getsize() << endl;
    cout << newQ.is_empty();
    return 0;
}