#include <iostream>
#include "String.h"
#include "BitString.h"

int main() {
    STRING* strings[5];  // Массив указателей на базовый класс

    int choice;
    int count = 0;
    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Create string\n";
        std::cout << "2. Create bitstring\n";
        std::cout << "3. Display string information\n";
        std::cout << "4. Invert bitstring\n";
        std::cout << "5. Add two bitstrings\n";
        std::cout << "6. Exit\n";
        std::cout << "Choose an action: ";
        std::cin >> choice;

        if (choice == 1) {
            char cstr[100];
            std::cout << "Enter string: ";
            std::cin >> cstr;
            strings[count] = new STRING(cstr);
            count++;
        }
        else if (choice == 2) {
            char bstr[100];
            std::cout << "Enter bitstring: ";
            std::cin >> bstr;
            strings[count] = new BITSTRING(bstr);
            count++;
        }
        else if (choice == 3) {
            for (int i = 0; i < count; ++i) {
                strings[i]->print();
            }
        }
        else if (choice == 4) {
            for (int i = 0; i < count; ++i) {
                BITSTRING* bs = dynamic_cast<BITSTRING*>(strings[i]);
                if (bs) {
                    bs->invert();
                    std::cout << "After sign inversion: ";
                    bs->print();
                }
            }
        }
        else if (choice == 5) {
            if (count >= 2) {
                BITSTRING* bs1 = dynamic_cast<BITSTRING*>(strings[count - 2]);
                BITSTRING* bs2 = dynamic_cast<BITSTRING*>(strings[count - 1]);
                if (bs1 && bs2) {
                    BITSTRING result = *bs1 + *bs2;
                    result.print();
                }
            }
        }
        else if (choice == 6) {
            break;
        }
    }

    // Освобождение памяти
    for (int i = 0; i < count; ++i) {
        delete strings[i];
    }

    return 0;
}