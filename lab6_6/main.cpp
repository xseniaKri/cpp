#include <iostream>
#include <string>

#include "myQueue.h"
#pragma comment(lib, "myQueue.lib")

using namespace std;

int min(int a, int b, int c) {
    if (a <= b & a <= c) return a;
    if (b <= a & b <= c) return b;
    if (c <= a & c <= b) return c;
}

void numbers(int n) {
    cout << "Your numbers are: ";

    myQueue q2, q3, q5, res;
    q2.enqueue(2);
    q3.enqueue(3);
    q5.enqueue(5);
    for (int i = 0; i < n; i++) {
        int temp = min(q2.get_top(), q3.get_top(), q5.get_top());
        res.enqueue(temp);
        q2.enqueue(temp*2);
        q3.enqueue(temp*3);
        q5.enqueue(temp*5);
        if (q2.get_top() == temp) int x = q2.dequeue();
        if (q3.get_top() == temp) int y = q3.dequeue();
        if (q5.get_top() == temp) int z = q5.dequeue();
    }
    while (!res.is_empty()) {
        cout << res.dequeue() << " ";
    }
    cout << endl;
}

int main() {
    while (true) {
    int n;
    cout << "Enter natural n, enter 0 for exit" << endl;
    cin >> n;
    if (n == 0) break;
    else numbers(n);
    }
    return 0;
}