#include <iostream>
#include <string>  // Для работы с C++ строками

using namespace std;

// Проверка строки на палиндром
bool isPalindrome(const string& str) {
    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

// Поиск подстроки в строке
int findSubstring(const string& str, const string& substr) {
    return str.find(substr); // find возвращает позицию или string::npos, что можно использовать как -1
}


// Шифр Цезаря
void caesarCipher(string& str, int shift) {
    int len = str.length();
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'a' + (str[i] - 'a' + shift) % 26; //перевод текущего символа str[i] в индекс в диапазоне от 0 до 25,  
            //добавляем shift к индексу символа и берем остаток от деления на 26 для зацикливания алфавита 
            //если сдвиг превышает z, мы вернемся к началу алфавита
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'A' + (str[i] - 'A' + shift) % 26;
        }
    }
}

// Вывод всех подстрок, заключенных в кавычки
void printQuotedText(const string& str) {
    bool inQuotes = false;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '"') {
            inQuotes = !inQuotes;  // Переключаем состояние внутри кавычек
            if (!inQuotes) {
                cout << endl; // Закрытие кавычек завершает вывод
            }
        } else if (inQuotes) {
            cout << str[i];  // Выводим символы, если они внутри кавычек
        }
    }
}


int main() {
    int choice;
    string str;
    string substr;
    int shift;

    do {
        cout << "Select an action:\n" 
        << "1. Check if a string is a palindrome\n"
        << "2. Find a substring within a string\n"
        << "3. Encrypt a string (Caesar cipher)\n"
        << "4. Print text inside quotes\n"
        << "5. Exit\n"
        << "Your choice: ";
        cin >> choice;
        cin.ignore();  // Очищаем символ новой строки после cin >> choice

        switch (choice) {
            case 1:
                cout << "Enter a string to check for palindrome: ";
                getline(cin, str);
                if (isPalindrome(str)) {
                    cout << "The string is a palindrome.\n";
                } else {
                    cout << "The string is not a palindrome.\n";
                }
                break;

            case 2:
                cout << "Enter the main string: ";
                getline(cin, str);
                cout << "Enter the substring to search for: ";
                getline(cin, substr);
                int pos;
                pos = findSubstring(str, substr);
                if (pos != string::npos) {  // Используем string::npos, если подстрока не найдена
                    cout << "Substring found at position: " << pos << endl;
                } else {
                    cout << "Substring not found.\n";
                }
                break;

            case 3:
                cout << "Enter a string to encrypt: ";
                getline(cin, str);
                cout << "Enter shift value: ";
                cin >> shift;
                cin.ignore();  // Очищаем символ новой строки после cin >> shift
                caesarCipher(str, shift);
                cout << "Encrypted string: " << str << endl;
                break;

            case 4:
                cout << "Enter text with quotes: ";
                getline(cin, str);
                cout << "Text inside quotes: ";
                printQuotedText(str);
                cout << endl;
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

        cout << endl;

    } while (choice != 5);

    return 0;
}