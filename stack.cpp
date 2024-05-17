//
// Created by Baekhil on 2024/5/17.
//

#include "stack.h"

void stack::demo(std::istream &in, stack &s) {
    char cmd;
    while (in >> cmd) {
        std::string input;
        switch (cmd) {
            case 'I':
                in >> input;
                s.push(input);
                break;
            case 'P':
                s.printString();
                break;
            case 'B':
                s.printBig5();
                break;
            case 'R':
                if (s.pop()) {
                    std::cout << "Success!" << std::endl;
                } else {
                    std::cout << "Failed! (The stack is empty.)" << std::endl;
                }
                break;
            case 'C':
                s.clear();
                std::cout << "Success!" << std::endl;
                break;
            case '?':
                in >> input;
                if (input.size() == 2) {
                    if (s.find(input)) {
                        std::cout << "Found!" << std::endl;
                    } else {
                        std::cout << "Not found!" << std::endl;
                    }
                } else {
                    std::cout << "Invalid input!" << std::endl;
                }
                break;
            case 'E':
                return;
            default:
                std::cout << "Invalid cmd!" << std::endl;
                break;
        }
    }
}

void stack::push(const std::string &inputString) {
    if (isFull()) {
        return;
    }
    for (char c: inputString) {
        ptr[++top] = c;
    }
}

bool stack::isFull() const {
    return top == size - 1;
}

void stack::printString() {
    if (isEmpty()) {
        std::cout << "The stack is empty!" << std::endl;
        return;
    }
    std::string str;
    for (int i = 0; i <= top; ++i) {
        str += ptr[i];
    }
    std::cout << str << std::endl;
}

bool stack::isEmpty() const {
    return top == -1;
}

void stack::printBig5() {
    if (isEmpty()) {
        std::cout << "The stack is empty!" << std::endl;
        return;
    }
    std::cout << "(" << (int) ptr[0] << ", " << (int) ptr[1] << ")";
    for (int i = 1; i <= top / 2; ++i) {
        std::cout << " " << "(" << (int) ptr[i * 2] << ", " << (int) ptr[i * 2 + 1] << ")";
    }
    std::cout << std::endl;
}

bool stack::pop() {
    if (isEmpty()) {
        return false;
    }
    top -= 2;
    return true;
}

void stack::clear() {
    top = -1;
}

bool stack::find(std::string ch) {
    for (int i = 0, j = 0; i <= top; ++i) {
        if (ptr[i] == ch[j]) {
            ++j;
        }
        if (j == 2) {
            return true;
        }
    }
    return false;
}
