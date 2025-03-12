#include "dyn_arr.h"
#include <stdexcept> // Для исключений
#include <iostream>

using namespace std;


template <typename T>
DynArr<T>::DynArr() {
    data = nullptr;
    size = 0;
}

template <typename T>
DynArr<T>::~DynArr() {
    delete[] data;
}

template <typename T>
void DynArr<T>::add(const T& value) {
    T* new_data = new T[size + 1];
    // Копия старого массива
    for (int i = 0; i < size; i++) {
        new_data[i] = data[i];
    }
    new_data[size] = value;
    size++;
    delete[] data;
    data = new_data;
}

template <typename T>
T& DynArr<T>::get(int index) {
    if (index >= size) { throw out_of_range("Index out of range"); }
    return data[index];
}

template <typename T>
int DynArr<T>::getSize() { return size; }

template <typename T>
void DynArr<T>::print() {
    for (int i = 0; i < size; i++) { cout << data[i] << ' '; }
}

template <typename T>
void DynArr<T>::swap(int i, int j) {
    if (i >= size || j >= size) {
        throw out_of_range("Index out of range");
    }
    T temp = data[i];  
    data[i] = data[j]; 
    data[j] = temp;
}