#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Функция для проверки ввода целого числа
bool getIntegerInput(int& number) {
    string input;
    getline(cin, input);
    stringstream ss(input);

    if (ss >> number && ss.eof()) {
        return true;
    }
    
    return false;
}

// Функция фильтрации тестов - оставляет только первую попытку каждого студента
void filterTests(const vector<pair<int, int>>& submissions) {
    unordered_set<int> seen_students; // Храним ID студентов, которые уже отправили тест
    
    cout << "Accepted results:\n";
    for (const auto& submission : submissions) {
        int student_id = submission.first;
        
        // Если студент еще не отправлял тест, добавляем его в результат
        if (seen_students.find(student_id) == seen_students.end()) {
            cout << "Student " << student_id << ": " << submission.second << '\n';
            seen_students.insert(student_id); // Отмечаем, что этот студент уже отправил тест
        }
    }
    system("pause");
    system("cls");
}

int main() {
    while (true) {
        system("cls");
        cout << "Lab 6_7. Done by Kripak Ksenia, group 241-326\nChoose an option:\n1. Check test results\n2. Exit\n";
        int choice;

        if (!getIntegerInput(choice) || (choice != 1 && choice != 2)) {
            cout << "Invalid input! Please enter 1 or 2.\n";
            system("pause");
            continue;  // Повторяем ввод
        }

        if (choice == 2) {
            cout << "Exiting...\n";
            break;
        }
        
        if (choice == 1) {
            system("cls");
            int n;
            cout << "Enter the number of students: ";
            
            if (!getIntegerInput(n) || n <= 0) {
                cout << "Invalid input! Number of students must be a positive integer.\n";
                system("pause");
                continue;
            }

            vector<pair<int, int>> submissions;
            
            for (int i = 0; i < n; i++) {
                int student_id, score;

                // Проверка ввода ID студента
                cout << "Enter student ID: ";
                if (!getIntegerInput(student_id)) {
                    cout << "Invalid student ID! Must be an integer.\n";
                    i--; // Повторяем ввод для этого студента
                    continue;
                }

                // Проверка ввода баллов
                cout << "Enter test score of student " << student_id << ": ";
                if (!getIntegerInput(score)) {
                    cout << "Invalid score! Must be an integer.\n";
                    i--; // Повторяем ввод
                    continue;
                }

                submissions.push_back({student_id, score});
            }
            
            filterTests(submissions);
        }
    }
    return 0;
}