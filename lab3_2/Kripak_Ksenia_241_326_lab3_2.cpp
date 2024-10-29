using namespace std;

#include <string>
#include <iostream>

// 1. Функция для ввода массива
void inputArray(int*& arr, int& size) {
    cout << "Enter the size of the array: ";
    cin >> size;
    
    if (arr != nullptr) {
        delete[] arr;
    }

    arr = new int[size];
    
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

// 2. Функция для вывода массива
void printArray(const int* arr, int size) {
    if (size == 0 || arr == nullptr) {
        cout << "The array is empty. Please input an array first.\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функция для подсчета суммы цифр числа, стоящих на четных местах
int sumOfEvenPositionDigits(int num) {
    int sum = 0;
    int index = 0;
    string strNum = to_string(num);
    
    for (int i = 0; i < strNum.size(); i++) {
        if (i % 2 == 1) { // четные позиции (индексация с нуля)
            sum += strNum[i] - '0'; // перевод char в цифру
        }
    }
    return sum;
}

// 3. Функция для сортировки по сумме цифр, стоящих на четных местах
void sortByEvenPositionDigitsSum(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (sumOfEvenPositionDigits(arr[j]) > sumOfEvenPositionDigits(arr[j + 1])) {
                int n = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = n;
            }
        }
    }
}


// Функция для получения последней цифры числа
int lastDigit(int num) {
    return abs(num) % 10;
}

// 4. Функция для сортировки массива: сначала по возрастанию последней цифры,а при совпадении последних цифр - по убыванию
void sortByLastDigitThenDescending(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (lastDigit(arr[j]) > lastDigit(arr[j + 1])) {
                int n = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = n;
            }
            else if (lastDigit(arr[j]) == lastDigit(arr[j + 1])) {
                if (arr[j] < arr[j + 1]) {
                    int n = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = n;  
                }
            }
        }
    }
}

// Главное меню
int main() {
    int *arr = nullptr; 
    int size = 0; 
    int choise = 10;

    while (choise != 5) {
        cout << "\nMenu:\n" << "1. Input new array\n" << "2. Print array\n" << "3. Sort by sum of digits in even positions\n" 
    << "4. Sort by last digit, then by descending order\n" << "5. Exit\n" << "Choose an option: ";
        cin >> choise;

        switch (choise) {
            case 1:
                inputArray(arr, size);
                break;
            case 2:
                cout << "Your array: ";
                printArray(arr, size);
                break;
            case 3:
                if (size > 0) {
                    sortByEvenPositionDigitsSum(arr, size);
                    cout << "Array sorted by sum of digits in even positions: ";
                    printArray(arr, size);
                } else {
                    cout << "Array is empty. Please input an array first.\n";
                }
                break;
            case 4:
                if (size > 0) {
                    sortByLastDigitThenDescending(arr, size);
                    cout << "Array sorted by last digit, then by descending order: ";
                    printArray(arr, size);
                } else {
                    cout << "Array is empty. Please input an array first.\n";
                }
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    if (arr != nullptr) {
        delete[] arr;
    }

    return 0;
}