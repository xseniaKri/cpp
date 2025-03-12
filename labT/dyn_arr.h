#pragma once
#include <stdexcept> // Для исключений
template <typename T>
class DynArr {
private:
    T* data;  
    int size;  

public:
    DynArr();
    ~DynArr();
    void add(const T& value);
    T& get(int index);
    int getSize();
    void print();
    void swap(int i, int j);
};

#include "dyn_arr.cpp"
