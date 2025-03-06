#include "myList.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <sstream>  // Для использования std::istringstream



void printMenu() {
    std::cout << "\tВыполнила Крипак Ксения, гр. 241-326\n";
    std::cout << "\t========================\n";
    std::cout << "\t1. Тест\n";
    std::cout << "\t2. Выход\n";
    std::cout << "\tВыберите действие: ";
}

int main() {
    List studentList;
    std::string choice;
    
    while (true) {
        system("clear");
        printMenu();
        std::cin >> choice;
        
        if (choice == "1") {
            std::cout << "Введите количество студентов: ";
            int kolvo;
            std::string num;
            std::cin.ignore();
            std::getline(std::cin, num);
            std::istringstream iss1(num);
            if (iss1 >> kolvo && kolvo > 0) {
                for (int i = 0; i < kolvo; i++) {
                    std::string input;
                    int groupNumber;
                    std::string surname;

                    std::cout << "Введите номер группы и фамилию студента (например: 12345 Иванов): ";
                    std::cin.ignore();  // Очищаем буфер ввода перед использованием getline
                    std::getline(std::cin, input);  // Получаем всю строку ввода

                    // Используем istringstream для разделения строки
                    std::istringstream iss(input);
                    if (iss >> groupNumber >> surname) {
                        if (groupNumber <= 0) {
                            std::cout << "Ошибка! Введите положительное целое число для номера группы.\n";
                            continue;
                        }
                        studentList.push(groupNumber, surname); 
                    } else {
                        std::cout << "Ошибка! Неверный формат ввода. Попробуйте снова.\n";
                    }
                }
            }
            else cout << " Ошибка! Введите целое положительное число!\n";
            
        }
        else if (choice == "2") {
            studentList.pop();
            std::cout << "Первая группа удалена.\n";
            std::cin.get();
        }
        else if (choice == "3") {
            studentList.clear();
            std::cout << "Список очищен.\n";
            std::cin.get();
        }
        else if (choice == "4") {
            studentList.print();
            std::cin.get();
        }
        else if (choice == "5") {
            break;
        }
        else {
            std::cout << "Неверный ввод. Попробуйте снова.\n";
            std::cin.get();
        }
        
        std::cin.get();
    }
    
    return 0;
}