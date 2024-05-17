//
// Created by Baekhil on 2024/5/17.
//

#ifndef REFERENCE_COUNTER_COUNTER_PTR_H
#define REFERENCE_COUNTER_COUNTER_PTR_H


#include <cstring>
#include "array_cell.h"

template<typename T>
class counter_ptr {
private:
    char *_name;
    array_cell<T> *_cell_ptr{};
public:
    counter_ptr(const char *name, T *memory);

    counter_ptr<T> &operator=(T *memory);

    explicit counter_ptr(const char *name);

    counter_ptr<T> &operator=(const counter_ptr<T> &rhs);

    virtual ~counter_ptr();

    T &operator[](std::size_t idx);

    void release();
};

template<typename T>
counter_ptr<T>::counter_ptr(const char *name, T *memory) {
    _name = new char[std::strlen(name) + 1];
    std::strcpy(_name, name);
    _cell_ptr = new array_cell<T>(memory);
    std::cout << "counter_ptr " << _name << " is assigned to an array_cell: counter " << _cell_ptr->getCounter()
              << std::endl;
}

template<typename T>
counter_ptr<T> &counter_ptr<T>::operator=(T *memory) {
    if (_cell_ptr) {
        if (_cell_ptr->decCounter() == 0) {
            delete _cell_ptr;
        }
    }
    _cell_ptr = new array_cell<T>(memory);
    std::cout << "counter_ptr " << _name << " is assigned to an array_cell: counter " << _cell_ptr->getCounter()
              << std::endl;
    return *this;
}

template<typename T>
counter_ptr<T>::counter_ptr(const char *name) {
    _name = new char[std::strlen(name) + 1];
    std::strcpy(_name, name);
    std::cout << "counter_ptr " << _name << " is not assigned to an array_cell!" << std::endl;
}

template<typename T>
counter_ptr<T> &counter_ptr<T>::operator=(const counter_ptr<T> &rhs) {
    if (this != &rhs) {   // handle self-assignment
        if (_cell_ptr) {
            if (_cell_ptr->decCounter() == 0) {
                delete _cell_ptr;
            }
        }
        _cell_ptr = rhs._cell_ptr;
        _cell_ptr->incCounter();
        std::cout << "counter_ptr " << _name << " is assigned to an array_cell: counter " << _cell_ptr->getCounter()
                  << std::endl;
    }
    return *this;
}

template<typename T>
counter_ptr<T>::~counter_ptr() {
    std::cout << "counter_ptr " << _name << " is deleted!" << std::endl;
    delete _name;
    if (_cell_ptr->decCounter() == 0) {
        delete _cell_ptr;
    }
}

template<typename T>
T &counter_ptr<T>::operator[](std::size_t idx) {
    return _cell_ptr->getMemory()[idx];
}

template<typename T>
void counter_ptr<T>::release() {
    _cell_ptr->decCounter();
    std::cout << "counter_ptr " << _name << " is not assigned to an array_cell!" << std::endl;
}


#endif //REFERENCE_COUNTER_COUNTER_PTR_H
