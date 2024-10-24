#include <iostream>
#include <string>
using namespace std;

// Пузырьковая сортировка
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Сортировка подсчетом для символов (a-z)
void countingSort(char arr[], int n) {
    int count[26] = {0};
    

    // Подсчет вхождений каждого символа
    for (int i = 0; i < n; i++) {
        count[arr[i] - 97]++;
    }
    
    // Строим отсортированный массив
    int index = 0;
    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {  // Пока есть вхождения текущего символа
            arr[index++] = i + 'a';  // Помещаем символ в массив
            count[i]--;  // Уменьшаем счетчик
        }
    }
}

// Сортировка слиянием
void merge(int arr[], int left, int mid, int right) {
    // Создаем два временных фиксированных массива для левой и правой части
    const int MAX_SIZE = 1000;
    int L[MAX_SIZE], R[MAX_SIZE];
    
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Копируем данные в временные массивы L[] и R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    // Инициализируем индексы для объединения обратно в основной массив
    int i = 0, j = 0, k = left;

    // Слияние массивов L и R обратно в arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы L[], если таковые остались
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Копируем оставшиеся элементы R[], если таковые остались
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Функция сортировки слиянием
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Рекурсивно сортируем каждую половину
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Сливаем отсортированные половины
        merge(arr, left, mid, right);
    }
}

int main() {
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Sort numeric array using bubble sort\n";
        cout << "2. Sort character array using counting sort\n";
        cout << "3. Sort numeric array using merge sort\n";
        cout << "4. Exit\n";

        int choice;
        cout << "Choose an option (1-4): ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the size of the numeric array (up to 1000): ";
            int n;
            cin >> n;
            if (n > 1000) {
                cout << "Error: the array size should not exceed 1000 elements.\n";
                continue;
            }

            int array[1000];
            cout << "Enter the elements of the array: ";
            for (int i = 0; i < n; i++) {
                int new_element;
                cin >> new_element;
                array[i] = new_element;
            }

            bubbleSort(array, n);

            cout << "Sorted array: ";
            for (int i = 0; i < n; i++) {
                cout << array[i] << " ";
            }
            cout << endl;

        } else if (choice == 2) {
            int n;
            cout << "Enter the length of the character array (up to 1000): ";
            cin >> n;
            if (n > 1000) {
                cout << "Error: the array length should not exceed 1000 characters.\n";
                continue;
            }

            char array[1000];
            cout << "Enter the characters (a-z): ";
            for (int i = 0; i < n; i++) {
                cin >> array[i];
            }

            countingSort(array, n);

            cout << "Sorted array: ";
            for (int i = 0; i < n; i++) {
                cout << array[i];
            }
            cout << endl;

        } else if (choice == 3) {
            int n;
            cout << "Enter the size of the numeric array (up to 1000): ";
            cin >> n;
            if (n > 1000) {
                cout << "Error: the array size should not exceed 1000 elements.\n";
                continue;
            }

            int array[1000];
            cout << "Enter the elements of the array: ";
            for (int i = 0; i < n; i++) {
                cin >> array[i];
            }

            mergeSort(array, 0, n - 1);

            cout << "Sorted array: ";
            for (int i = 0; i < n; i++) {
                cout << array[i] << " ";
            }
            cout << endl;

        } else if (choice == 4) {
            cout << "Exiting the program.\n";
            break;

        } else{
            cout << "Invalid choice, please try again.\n";
            continue;
        }
    }

    return 0;
    
}

