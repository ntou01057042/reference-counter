//
// Created by Baekhil on 2024/5/17.
//

#ifndef REFERENCE_COUNTER_ARRAY_CELL_H
#define REFERENCE_COUNTER_ARRAY_CELL_H


#include <iostream>

template<typename T>
class array_cell {
private:
    int _counter;
    T *_memory;
public:
    explicit array_cell(T *memory);

    [[nodiscard]] int getCounter() const;

    void setCounter(int counter);

    void setMemory(T *memory);

    [[nodiscard]] T *getMemory() const;

    virtual ~array_cell();

    int decCounter();

    int incCounter();
};

template<typename T>
array_cell<T>::array_cell(T *memory) {
    _memory = memory;
    std::cout << "array_cell is allocated!" << std::endl;
    _counter = 1;
}

template<typename T>
int array_cell<T>::getCounter() const {
    return _counter;
}

template<typename T>
void array_cell<T>::setCounter(int counter) {
    if (counter >= 0) {
        _counter = counter;
    }
}

template<typename T>
void array_cell<T>::setMemory(T *memory) {
    _memory = memory;
}

template<typename T>
T *array_cell<T>::getMemory() const {
    return _memory;
}

template<typename T>
array_cell<T>::~array_cell() {
    delete _memory;
}

template<typename T>
int array_cell<T>::decCounter() {
    setCounter(getCounter() - 1);
    if (getCounter() == 0) {
        std::cout << "array_cell counter " << getCounter() << ": deleted" << std::endl;
    } else if (getCounter() > 0) {
        std::cout << "array_cell counter is decreased: counter " << getCounter() << std::endl;
    }
    return getCounter();
}

template<typename T>
int array_cell<T>::incCounter() {
    setCounter(getCounter() + 1);
    std::cout << "array_cell counter is increased: counter " << getCounter() << std::endl;
    return getCounter();
}


#endif //REFERENCE_COUNTER_ARRAY_CELL_H
