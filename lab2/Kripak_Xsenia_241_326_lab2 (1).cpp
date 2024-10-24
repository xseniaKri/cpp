#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// задание 1
void Triangle(int n) 
{
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << j;
        }
        cout << endl;
    }
}

// задание 2
unsigned long long Binom(int n, int k)
{
    if (k > n / 2) k = n - k;
    if (k == 1)  return n;
    if (k == 0)  return 1;
    unsigned long long res = 1;
    return Binom(n-1,k) + Binom(n-1,k-1);

}

// задание 3
void Mean()
{
    double res, sum;
    sum = 0;
    int count = 0;
    while (true) {
        cout << "Enter number for sum or enter '00000' for exit: ";
        double num = 0;
        cin >> num;
        if (num == 00000) {
            if (sum == 0) {
                cout << "0\nExiting to Menu...";
                break;
            }
            else {
                cout << "Arithmetic mean: " << sum / count << "\nExiting to Menu...\n";
                break;
            }
        }
        else {
            sum = sum + num;
            count += 1;
        }
        }
}


int main()
{
    int choice = 0;
    //меню
    while (choice != 4) {
        cout << "Menu"
            << "\n 1. Numeric triangle"
            << "\n 2. Binominal coefficients"
            << "\n 3. Arithmetic mean"
            << "\n 4. Exit"
            << "\n Select action : ";
        cin >> choice;
        switch (choice) {
        case 1:
        {
            cout << "Please enter a positive integer: ";
            int num;
            cin >> num;
            Triangle(num);
            break;
        }
        case 2:
        {
            cout << "Please enter positive integer n (n < 100): ";
            int n;
            cin >> n;
            if (n < 0 || n >= 100) {
                cout << "Error. Please enter positive integer n (n < 100): ";
            }
            else {
                for (int k = 0; k <= n; k++) {
                    cout << Binom(n, k) << " ";
                }
            }
            cout << endl;
            break;
        }
        case 3:
            Mean();
            break;
        }
    }
    cout << "Exiting...";
    return 0;
}