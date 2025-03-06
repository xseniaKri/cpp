#include "myList.h"
#include "myList.cpp"
#include <windows.h>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <sstream>  // Для использования std::istringstream

// Функция для изменения цвета текста
void setTextColor(WORD color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printMenu() {
    // Сохраняем стандартный цвет текста
    WORD originalColor;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    originalColor = consoleInfo.wAttributes;

    // Изменяем цвет текста на фиолетовый
    setTextColor(5); // Фиолетовый цвет (код 5)

    std::cout << "\n\t\t========================\n";
    std::cout << "\t\t    ТЕСТИРОВАНИЕ LIST \n";
    std::cout << "\t\t========================\n";
    
    // Возвращаем стандартный цвет
    setTextColor(originalColor);

    std::cout << "\t1. Добавить студента (push)\n";
    std::cout << "\t2. Удалить первую группу (pop)\n";
    std::cout << "\t3. Очистить список группы (clear)\n";
    std::cout << "\t4. Показать список группы (print)\n";
    std::cout << "\t5. Выход\n";
    std::cout << "\tВыберите действие: ";
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    List studentList;
    std::string choice;
    
    while (true) {
        clearScreen();
        printMenu();
        std::cin >> choice;
        
        if (choice == "1") {
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
                studentList.push(groupNumber, surname);  // Добавляем студента в список
            } else {
                std::cout << "Ошибка! Неверный формат ввода. Попробуйте снова.\n";
            }
        }
        else if (choice == "2") {
            studentList.pop();
            std::cout << "Первая группа удалена.\n";
        }
        else if (choice == "3") {
            studentList.clear();
            std::cout << "Список очищен.\n";
        }
        else if (choice == "4") {
            studentList.print();
        }
        else if (choice == "5") {
            break;
        }
        else {
            std::cout << "Неверный ввод. Попробуйте снова.\n";
        }
        
        system("pause");
    }
    
    return 0;
}