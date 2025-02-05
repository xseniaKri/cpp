#include "String.h"
#include <cstring>
#include <iostream>

int STRING::copyCount = 0;

STRING::STRING() : str(nullptr), length(0) {}

STRING::STRING(const char* cstr) {
    if (cstr) {
        length = strlen(cstr);
        str = new char[length + 1];
        strcpy(str, cstr);
    } else {
        str = nullptr;
        length = 0;
    }
}

STRING::STRING(char c) {
    length = 1;
    str = new char[length + 1];
    str[0] = c;
    str[1] = '\0';
}

STRING::STRING(const STRING& other) {
    copyCount++;
    length = other.length;
    str = new char[length + 1];
    strcpy(str, other.str);
}

int STRING::getLength() const {
    return length;
}

void STRING::clear() {
    delete[] str;
    str = nullptr;
    length = 0;
}

STRING::~STRING() {
    delete[] str;
}

void STRING::print() const {
    if (str) {
        std::cout << "String: " << str << ", length: " << length * 8 << " bits" << std::endl;
    } else {
        std::cout << "String is empty" << std::endl;
    }
}

int STRING::getCopyCount() {
    return copyCount;
}