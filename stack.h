//
// Created by Baekhil on 2024/5/17.
//

#ifndef REFERENCE_COUNTER_STACK_H
#define REFERENCE_COUNTER_STACK_H


#include "counter_ptr.h"

class stack {
private:
    int size;
    int top;
    counter_ptr<char> ptr;
public:
    explicit stack(int size = 100) : size(size), top(-1), ptr("stack", new char[size]) {}

    static void demo(std::istream &in, stack &s);

    void push(const std::string &inputString);

    [[nodiscard]] bool isFull() const;

    void printString();

    [[nodiscard]] bool isEmpty() const;

    void printBig5();

    bool pop();

    void clear();

    bool find(std::string ch);
};


#endif //REFERENCE_COUNTER_STACK_H
