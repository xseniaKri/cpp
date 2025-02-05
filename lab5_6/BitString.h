#ifndef BITSTRING_H
#define BITSTRING_H

#include "String.h"

class DLL_EXPORT BITSTRING : public STRING {
public:
    BITSTRING();
    BITSTRING(const char* cstr);
    BITSTRING(const BITSTRING& other);
    void invert();
    BITSTRING& operator=(const BITSTRING& other);
    BITSTRING operator+(const BITSTRING& other) const;
    bool operator==(const BITSTRING& other) const;
    virtual ~BITSTRING();
};

#endif // BITSTRING_H
