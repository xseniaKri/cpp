#include <iostream>
#include <vector>
#include <string>
#include <limits> // Для очистки потока ввода
#include <cstdlib> // Для system("clear")

using namespace std;

// ==================== Шаблон быстрой сортировки ====================

template <typename T>
int partition(vector<T>& arr, int low, int high, bool (*compare)(const T&, const T&)) {
    T pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (compare(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
void quicksort(vector<T>& arr, int low, int high, bool (*compare)(const T&, const T&)) {
    if (low < high) {
        int pivot = partition(arr, low, high, compare);
        quicksort(arr, low, pivot - 1, compare);
        quicksort(arr, pivot + 1, high, compare);
    }
}

// ==================== Структура Human ====================

struct Human {
    string surname;
    string name;
    int age;
    Human(string s, string n, int a) : surname(s), name(n), age(a) {}
};

// Функции сравнения
bool compareBySurname(const Human& a, const Human& b) { return a.surname < b.surname; }
bool compareByName(const Human& a, const Human& b) { return a.name < b.name; }
bool compareByAge(const Human& a, const Human& b) { return a.age < b.age; }

// ==================== Функции сравнения для базовых типов ====================

template <typename T> bool ascending(const T& a, const T& b) { return a < b; }
template <typename T> bool descending(const T& a, const T& b) { return a > b; }

// ==================== Вспомогательная функция вывода ====================

template <typename T>
void printArray(const vector<T>& arr) {
    for (const auto& el : arr) {
        cout << el << " ";
    }
    cout << endl;
}

void printArray(const vector<Human>& arr) {
    for (const auto& el : arr) {
        cout << el.surname << " " << el.name << " " << el.age << endl;
    }
}

// ==================== Тесты сортировки ====================

void testSortingIntegers() {
    vector<int> numbers = {5, 3, 8, 1, 4, 7, 2};
    cout << "Исходный массив: ";
    printArray(numbers);

    quicksort(numbers, 0, numbers.size() - 1, ascending<int>);
    cout << "По возрастанию: ";
    printArray(numbers);

    quicksort(numbers, 0, numbers.size() - 1, descending<int>);
    cout << "По убыванию: ";
    printArray(numbers);
}

void testSortingFloats() {
    vector<double> numbers = {3.14, 2.71, 1.41, 4.0, 2.5, 5.9};
    cout << "Исходный массив: ";
    printArray(numbers);

    quicksort(numbers, 0, numbers.size() - 1, ascending<double>);
    cout << "По возрастанию: ";
    printArray(numbers);

    quicksort(numbers, 0, numbers.size() - 1, descending<double>);
    cout << "По убыванию: ";
    printArray(numbers);
}

void testSortingStrings() {
    vector<string> words = {"apple", "orange", "banana", "grape", "cherry"};
    cout << "Исходный массив: ";
    printArray(words);

    quicksort(words, 0, words.size() - 1, ascending<string>);
    cout << "По алфавиту: ";
    printArray(words);

    quicksort(words, 0, words.size() - 1, descending<string>);
    cout << "В обратном порядке: ";
    printArray(words);
}

void testSortingBooleans() {
    vector<bool> bools = {true, false, true, false, true, false};
    cout << "Исходный массив: ";
    printArray(bools);

    quicksort(bools, 0, bools.size() - 1, ascending<bool>);
    cout << "False -> True: ";
    printArray(bools);

    quicksort(bools, 0, bools.size() - 1, descending<bool>);
    cout << "True -> False: ";
    printArray(bools);
}

void testSortingHumans() {
    vector<Human> people = {
        Person("Ivanov", "Ivan", 30),
        Person("Petrov", "Petr", 25),
        Person("Sidorov", "Semen", 35),
        Person("Alexeev", "Alexey", 28),
        Person("Nikolaev", "Nikolay", 22)
    };

    cout << "Исходный список:\n";
    printArray(people);

    cout << "\nСортировка по фамилии:\n";
    quicksort(people, 0, people.size() - 1, compareBySurname);
    printArray(people);

    cout << "\nСортировка по имени:\n";
    quicksort(people, 0, people.size() - 1, compareByName);
    printArray(people);

    cout << "\nСортировка по возрасту:\n";
    quicksort(people, 0, people.size() - 1, compareByAge);
    printArray(people);
}

// ==================== Безопасный ввод числа ====================

int getIntInput() {
    int choice;
    while (true) {
        cout << "Ваш выбор: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear(); // Сброс флага ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
            cout << "Ошибка! Введите целое число.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка лишних символов
            return choice;
        }
    }
}

// ==================== Меню ====================

int main() {
    while (true) {
        cout << "\nВыберите тест сортировки:\n";
        cout << "1. Сортировка целых чисел\n";
        cout << "2. Сортировка дробных чисел\n";
        cout << "3. Сортировка строк\n";
        cout << "4. Сортировка булевых значений\n";
        cout << "5. Сортировка структуры Person (Фамилия, Имя, Возраст)\n";
        cout << "0. Выход\n";

        int choice = getIntInput();

        system("clear");

        switch (choice) {
            case 1: testSortingIntegers(); break;
            case 2: testSortingFloats(); break;
            case 3: testSortingStrings(); break;
            case 4: testSortingBooleans(); break;
            case 5: testSortingPersons(); break;
            case 0: return 0;
            default: cout << "Некорректный выбор! Попробуйте снова.\n";
        }

        cout << "\nНажмите Enter для возврата в меню...";
        cin.ignore(); // Ждем нажатия Enter
        system("clear");
    }
}
