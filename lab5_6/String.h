#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>
#include <stdexcept>

#ifdef _WIN32
    #define DLL_EXPORT __declspec(dllexport)
    #define DLL_IMPORT __declspec(dllimport)
#else
    #define DLL_EXPORT
    #define DLL_IMPORT
#endif

class DLL_EXPORT STRING {
protected:
    char* str;
    int length; // длина строки в битах

public:
    static int copyCount; // статическая переменная для подсчета копий

    STRING();
    STRING(const char* cstr);
    STRING(char c);
    STRING(const STRING& other);
    int getLength() const;
    void clear();
    virtual ~STRING();

    virtual void print() const;
    static int getCopyCount();
};

#endif // STRING_H
