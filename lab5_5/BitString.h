#pragma once

#include "String.h"

class BITSTRING : public STRING {
public:
    // Конструктор без параметров
    BITSTRING() : STRING() {}

    // Конструктор, принимающий C-строку
    BITSTRING(const char* cstr) : STRING() {
        if (cstr) {
            int len = strlen(cstr);
            for (int i = 0; i < len; ++i) {
                if (cstr[i] != '0' && cstr[i] != '1') {
                    clear();
                    return;
                }
            }
            length = len;
            str = new char[length + 1];
            strcpy(str, cstr);
        } else {
            str = nullptr;
            length = 0;
        }
    }

    // Конструктор копирования
    BITSTRING(const BITSTRING& other) : STRING(other) {}

    // Изменение знака на противоположный
    void invert() {
        for (int i = 0; i < length; ++i) {
            str[i] = (str[i] == '0') ? '1' : '0';
        }
    }

    // Операция присваивания
    BITSTRING& operator=(const BITSTRING& other) {
        if (this != &other) {
            clear();
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    // Операция сложения (арифметическая сумма)
    BITSTRING operator+(const BITSTRING& other) const {
        int maxLength = std::max(length, other.length);
        BITSTRING result;
        result.length = maxLength + 1;
        result.str = new char[result.length + 1];

        // Простой пример сложения (работа с двоичными строками)
        int carry = 0;
        for (int i = maxLength - 1; i >= 0; --i) {
            int a = (i < length && str[i] == '1') ? 1 : 0;
            int b = (i < other.length && other.str[i] == '1') ? 1 : 0;
            int sum = a + b + carry;
            result.str[i + 1] = (sum % 2) ? '1' : '0';
            carry = sum / 2;
        }
        result.str[0] = carry ? '1' : '0';
        result.str[result.length] = '\0';
        return result;
    }

    // Операция сравнения
    bool operator==(const BITSTRING& other) const {
        return (length == other.length) && (strcmp(str, other.str) == 0);
    }

    // Деструктор
    virtual ~BITSTRING() {}
};