#include <iostream>
#include <map>
#include <sstream>
#include <iomanip>
#include <windows.h>

using namespace std;

//Функция для подсчета появления каждого слова в процентах
void countWordFrequency(const string& text) {
    map<string, int> wordCount;
    stringstream ss(text);
    string word;
    int totalWords = 0;

    // Подсчет количества каждого слова
    while (ss >> word) {
        wordCount[word]++;
        totalWords++;
    }

    // Вывод результата
    if (totalWords == 0) {
        cout << "You entered an empty string. No words.\n";
    }
    else {
        cout << "Word frequency in percentage:\n";
        for (const auto& entry : wordCount) {
            double percentage = (entry.second * 100.0) / totalWords;
            cout << entry.first << ": " << fixed << setprecision(2) << percentage << "%\n";
        }
    }
    
    system("pause");
    system("cls");
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string choice;
    
    while (true) {
        system("cls");
        cout << "Choose an option:\n";
        cout << "1. Test word frequency\n";
        cout << "2. Exit\n";
        cout << "Enter your choice (1 or 2): ";
        getline(cin, choice);

        if (choice == "1") {
            cout << "Enter a text:\n";
            string text;
            getline(cin, text);

            countWordFrequency(text);
        } 
        else if (choice == "2") {
            cout << "Exiting the program.\n";
            break;
        } 
        else {
            cout << "Invalid choice, please choose 1 or 2.\n";
            system("pause");
        }
    }

    return 0;
}
