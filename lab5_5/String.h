#pragma once

#include <iostream>
#include <cstring>
#include <stdexcept>

class STRING {
protected:
    char* str;
    int length; // длина строки в битах

public:
    static int copyCount; // статическая переменная для подсчета копий

    // Конструктор без параметров
    STRING() : str(nullptr), length(0) {}

    // Конструктор, принимающий C-строку
    STRING(const char* cstr) {
        if (cstr) {
            length = strlen(cstr);
            str = new char[length + 1];
            strcpy(str, cstr);
        } else {
            str = nullptr;
            length = 0;
        }
    }

    // Конструктор, принимающий один символ
    STRING(char c) {
        length = 1;
        str = new char[length + 1];
        str[0] = c;
        str[1] = '\0';
    }

    // Конструктор копирования
    STRING(const STRING& other) {
        copyCount++;
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    // Получение длины строки
    int getLength() const {
        return length;
    }

    // Очистка строки
    void clear() {
        delete[] str;
        str = nullptr;
        length = 0;
    }

    // Деструктор
    virtual ~STRING() {
        delete[] str;
    }

    // Вывод строки
    virtual void print() const {
        if (str) {
            std::cout << "String: " << str << ", length: " << length * 8 << " bits" << std::endl;
        } else {
            std::cout << "String is empty" << std::endl;
        }
    }

    // Статический метод для получения количества копий
    static int getCopyCount() {
        return copyCount;
    }
};

// Инициализация статической переменной
int STRING::copyCount = 0;