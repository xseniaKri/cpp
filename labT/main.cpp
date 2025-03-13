#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <cstdlib>
#include <random>
#include <ctime>
#include <cctype>
#include <algorithm>

#include "dyn_arr.h"

using namespace std;

// Быстрая сортировка
template <typename T, typename Compare>
void quick_sort(DynArr<T>& arr, int start, int end, Compare cmp) {
    if (start < end) {
        T X = arr.get(start + rand() % (end - start)); // Опорный элемент берем случай
        int R = start, L = end;  

        while (R <= L) { 
            while (cmp(arr.get(R), X)) R++; 
            while (cmp(X, arr.get(L))) L--;

            if (R <= L) {
                arr.swap(R, L); 
                R++;
                L--;
            }
        }

        quick_sort<T, Compare>(arr, start, L, cmp); 
        quick_sort<T, Compare>(arr, R, end, cmp);
    }
}

// Структура  <Surname, Name, Age>
 
struct Human {
    string Surname;
    string Name;
    int Age;

    void print() const {
        cout << Surname << " " << Name << ", " << "возраст: " << Age << endl;
    }
};

// Сравнения для встроенных типов и для Структуры
template <typename T>
bool compare_asc(const T& a, const T& b) {
    return a < b;
}

template <typename T>
bool compare_desc(const T& a, const T& b) {
    return a > b;
}

bool cmp_surname(const Human& a, const Human& b) {
    return a.Surname < b.Surname;
}

bool cmp_name(const Human& a, const Human& b) {
    return a.Name < b.Name;
}

bool cmp_age(const Human& a, const Human& b) {
    return a.Age < b.Age;
}

bool cmp_surname_desc(const Human& a, const Human& b) {
    return a.Surname > b.Surname;
}

bool cmp_name_desc(const Human& a, const Human& b) {
    return a.Name > b.Name;
}

bool cmp_age_desc(const Human& a, const Human& b) {
    return a.Age > b.Age;
}


// Проверки на корректноcть для встроенных типов

bool is_valid_number(const string& str) {
    if (str.empty()) return false;
    size_t i = 0;
    if (str[i] == '-' || str[i] == '+') i++;
    for (; i < str.length(); i++) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}

bool is_valid_float(const string& str) {
    if (str.empty()) return false;
    
    size_t i = 0;
    if (str[i] == '-' || str[i] == '+') i++;
    
    bool has_dot = false;
    bool has_digit = false;

    for (; i < str.length(); i++) {
        if (isdigit(str[i])) {
            has_digit = true;
        } else if (str[i] == '.' && !has_dot) {
            has_dot = true;
        } else {
            return false;
        }
    }

    return has_digit;
}

bool is_valid_bool(const string& str) {
    string lower_str = str;
    transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
    return lower_str == "true" || lower_str == "false";
}

bool is_valid_word(const string& str) {
    if (str.empty()) return false;
    
    for (char c : str) {
        if (!isalpha(c)) return false;
    }
    return true;
}

bool is_valid_char_sequence(const string& str) {
    if (str.empty()) return false;

    istringstream iss(str);
    string token;

    while (iss >> token) {
        if (token.length() != 1) {
            return false;
        }
    }

    return true;
}

// Тесты разных типов

void test_int() {
    system("clear");
    DynArr<int> arr;
    cout << "Введите целые числа через пробел: ";
    string input;
    getline(cin, input);
    stringstream ss(input);
    string token;
    bool valid = true;

    while (ss >> token) {
        if (is_valid_number(token)) {
            arr.add(stoi(token));
        } else {
            cout << "Ошибка: '" << token << "' не является целым числом!\n";
            valid = false;
        }
    }

    if (arr.getSize() > 0) {
        quick_sort(arr, 0, arr.getSize() - 1, compare_asc<int>);
        cout << "Отсортированный массив по возрастанию: ";
        arr.print();
        cout << "\n";
        quick_sort(arr, 0, arr.getSize() - 1, compare_desc<int>);
        cout << "Отсортированный массив по убыванию: ";
        arr.print();
        cout << endl;
    } else {
        cout << "Массив пуст!" << endl;
    }
    cin.get();
}

void test_double() {
    system("clear");
    DynArr<double> arr;
    cout << "Введите числа с плавающей точкой через пробел: ";
    string input;
    getline(cin, input);
    stringstream ss(input);
    string token;
    bool valid = true;

    while (ss >> token) {
        if (is_valid_float(token)) {
            arr.add(stod(token));
        } else {
            cout << "Ошибка: '" << token << "' не является числом с плавающей точкой!\n";
            valid = false;
        }
    }

    if (arr.getSize() > 0) {
        quick_sort(arr, 0, arr.getSize() - 1, compare_asc<double>);
        cout << "Отсортированный массив по возрастанию: ";
        arr.print();
        cout << "\n";
        quick_sort(arr, 0, arr.getSize() - 1, compare_desc<double>);
        cout << "Отсортированный массив по убыванию: ";
        arr.print();
        cout << endl;
    } else {
        cout << "Массив пуст!" << endl;
    }
    cin.get();
}

void test_bool() {
    system("clear");
    DynArr<bool> arr;
    cout << "Введите булевы значения (true/false) через пробел: ";
    string input;
    getline(cin, input);
    stringstream ss(input);
    string token;
    bool valid = true;

    while (ss >> token) {
        if (is_valid_bool(token)) {
            arr.add(token == "true");
        } else {
            cout << "Ошибка: '" << token << "' не является булевым значением!\n";
            valid = false;
        }
    }

    if (arr.getSize() > 0) {
        quick_sort(arr, 0, arr.getSize() - 1, compare_asc<bool>);
        cout << "Отсортированный массив по возрастанию: ";
        arr.print();
        cout << "\n";
        quick_sort(arr, 0, arr.getSize() - 1, compare_desc<bool>);
        cout << "Отсортированный массив по убыванию: ";
        arr.print();
        cout << endl;
    } else {
        cout << "Массив пуст!" << endl;
    }
    cin.get();
}

void test_string() {
    system("clear");
    DynArr<string> arr;
    cout << "Введите слова через пробел: ";
    string input;
    getline(cin, input);
    stringstream ss(input);
    string token;

    while (ss >> token) {
        if (is_valid_word(token)) {
            arr.add(token);
        } else {
            cout << "Ошибка: '" << token << "' содержит недопустимые символы!\n";
        }
    }

    if (arr.getSize() > 0) {
        quick_sort(arr, 0, arr.getSize() - 1, compare_asc<string>);
        cout << "Отсортированный массив по возрастанию: ";
        arr.print();
        cout << "\n";
        quick_sort(arr, 0, arr.getSize() - 1, compare_desc<string>);
        cout << "Отсортированный массив по убыванию: ";
        arr.print();
        cout << endl;
    } else {
        cout << "Массив пуст!" << endl;
    }
    cin.get();
}

void test_char() {
    system("clear");
    DynArr<char> arr;
    cout << "Введите одиночные символы через пробел: ";
    string input;
    getline(cin, input);
    stringstream ss(input);
    string token;

    while (ss >> token) {
        if (is_valid_char_sequence(token)) {
            arr.add(token[0]);
        } else {
            cout << "Ошибка: '" << token << "' не является одиночным символом!\n";
        }
    }

    if (arr.getSize() > 0) {
        quick_sort(arr, 0, arr.getSize() - 1, compare_asc<char>);
        cout << "Отсортированный массив по возрастанию: ";
        arr.print();
        cout << "\n";
        quick_sort(arr, 0, arr.getSize() - 1, compare_desc<char>);
        cout << "Отсортированный массив по убыванию: ";
        arr.print();
        cout << endl;
    } else {
        cout << "Массив пуст!" << endl;
    }
    cin.get();
}

void test_struct() {
    system("clear");
    DynArr<Human> arr;
    cout << "Введите записи в формате: Фамилия Имя Возраст (каждую запись с новой строки, пустая строка - завершение ввода)\n";

    while (true) {
        Human person;
        cout << "Фамилия: ";
        getline(cin, person.Surname);
        if (person.Surname.empty()) break;

        cout << "Имя: ";
        getline(cin, person.Name);
        if (person.Name.empty()) break;

        cout << "Возраст: ";
        string age_str;
        getline(cin, age_str);
        if (age_str.empty()) break;

        if (!is_valid_number(age_str)) {
            cout << "Ошибка: '" << age_str << "' не является корректным возрастом!\n";
            continue;
        }

        person.Age = stoi(age_str);
        arr.add(person);
    }


    if (arr.getSize() == 0) {
        cout << "Список пуст!\n";
        return;
    }
    quick_sort(arr, 0, arr.getSize() - 1, cmp_surname);
    cout << "\nСортировка по фамилии по возрастанию:\n";
    for (int i = 0; i < arr.getSize(); i++) {
        arr.get(i).print();
    }
    quick_sort(arr, 0, arr.getSize() - 1, cmp_surname_desc);
    cout << "\nСортировка по фамилии по убыванию:\n";
    for (int i = 0; i < arr.getSize(); i++) {
        arr.get(i).print();
    }
    cout << endl;

    quick_sort(arr, 0, arr.getSize() - 1, cmp_name);
    cout << "\nСортировка по имени по возрастанию:\n";
    for (int i = 0; i < arr.getSize(); i++) {
        arr.get(i).print();
    }
    quick_sort(arr, 0, arr.getSize() - 1, cmp_name_desc);
    cout << "\nСортировка по имени по убыванию:\n";
    for (int i = 0; i < arr.getSize(); i++) {
        arr.get(i).print();
    }
    cout << endl;

    quick_sort(arr, 0, arr.getSize() - 1, cmp_age);
    cout << "\nСортировка по возрасту по возрастанию:\n";
    for (int i = 0; i < arr.getSize(); i++) {
        arr.get(i).print();
    }
    quick_sort(arr, 0, arr.getSize() - 1, cmp_age_desc);
    cout << "\nСортировка по возрасту по убыванию:\n";
    for (int i = 0; i < arr.getSize(); i++) {
        arr.get(i).print();
    }
    cin.get();
}



int main() {
    string choice;
    srand(time(NULL));  // Инициализация генератора случайных чисел
    do {
        system("clear");
        cout << "\t Выполнила Крипак Ксения, группа 241-326 \n";
        cout << "Задание: реализовать быструю сортировку любого типа данных и структуры {Name, Surname, Age}.\nВстроенными типами данных пользоваться нельзя.\n";
        cout << "Выберите тип для демонстрации работы функции quick_sort:\n";
        cout << "\n1 - Целые числа\n2 - Числа с плавающей точкой\n3 - Булевы значения\n4 - Строки (слова)\n5 - Символы\n6 - Структура <Surname, Name, Age>\n0 - Выход из программы\n";
        cin >> choice;
        cin.ignore();
        if (choice == "1") test_int();
        else if (choice == "2") test_double();
        else if (choice == "3") test_bool();
        else if (choice == "4") test_string();
        else if (choice == "5") test_char();
        else if (choice == "6") test_struct();
        else if (choice != "0") {
            cout << "Некорректный выбор! Введите цифру 0-5";
            cin.get();
            continue;
        }
    } while (choice != "0");

    return 0;
}
