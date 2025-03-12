#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <cstdlib>
#include <random>
#include <ctime>

#include "dyn_arr.h"

using namespace std;

// Быстрая сортировка
template <typename T>
void quick_sort(DynArr<T>& arr, int start, int end) {
    if (start < end) {
        int X = arr.get(start + rand() % (end - start)); // Опорный элемент случайный, пытаемся избежать худшего случая
        int R = start, L = end;  

        while (R <= L) { 
            while (arr.get(R) < X) R++; 
            while (arr.get(L) > X) L--;

            if (R <= L) {
                arr.swap(R, L); 
                R++;
                L--;
            }
        }

        quick_sort(arr, start, L); 
        quick_sort(arr, R, end);
    }
}


// Проверка на корректное число
bool isValidNumber(const string& str) {
    if (str.empty()) return false;
    size_t i = 0;
    if (str[i] == '-' || str[i] == '+') i++;
    for (; i < str.length(); i++) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}

int main() {
    system("clear");
    srand(time(NULL));  // Инициализация генератора случайных чисел

    DynArr<int> arr;
    cout << "Введите целые числа через пробел: ";
    string input;
    getline(cin, input);
    stringstream ss(input);
    string token;
    bool valid = true;

    while (ss >> token) {
        if (isValidNumber(token)) {
            arr.add(stoi(token));
        } else {
            cout << "Ошибка: '" << token << "' не является целым числом!\n";
            valid = false;
        }
    }

    if (arr.getSize() > 0) {
        quick_sort(arr, 0, arr.getSize() - 1);
        arr.print();
        cout << endl;
    } else {
        cout << "Массив пуст!" << endl;
    }

    return 0;
}
