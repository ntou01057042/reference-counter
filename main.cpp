#include <iostream>
#include "counter_ptr.h"
#include "stack.h"

void Part123();

void Part4();

int main() {
    Part123();
    Part4();
    return 0;
}

void Part4() {
    std::cout << std::endl;
    stack s;
    stack::demo(std::cin, s);
}

void Part123() {
    // Part 1
    counter_ptr<int> b("b", new int[10]);
    // stdout: int_array_cell is allocated
    // stdout: counter_ptr b is assigned to an int_array_cell: counter 1
    std::cout << std::endl;

    {
        b = new int[100];
        // stdout: int_array_cell counter 0: deleted
        // stdout: int_array_cell is allocated
        // stdout: counter_ptr b is assigned to an int_array_cell: counter 1
        std::cout << std::endl;

        counter_ptr<int> a("a");
        // stdout: counter_ptr a is not assigned to an int_array_cell
        std::cout << std::endl;

        a = b;
        // stdout: int_array_cell counter is increased: counter 2
        // stdout: counter_ptr a is assigned to an int_array_cell: counter 2
        std::cout << std::endl;
    }
    // a leaves it scope.
    // stdout: counter_ptr a is deleted
    // stdout: int_array_cell counter is decreased: counter 1
    std::cout << std::endl;

    // Part 2
    for (int i = 0; i < 10; ++i) {
        b[i] = i;
    }
    for (int i = 0; i < 10; ++i) {
        std::cout << b[i] << " ";
    }
    // stdout: 0 1 2 3 4 5 6 7 8 9
    std::cout << std::endl;

    counter_ptr<int> c("c");
    // stdout: counter_ptr c is not assigned to an int_array_cell
    std::cout << std::endl;

    c = b;
    // stdout: int_array_cell counter is increased: counter 2
    // stdout: counter_ptr c is assigned to an int_array_cell: counter 2
    std::cout << std::endl;

    b.release();
    // stdout: int_array_cell counter is decreased: counter 1
    // stdout: counter_ptr b is not assigned to an int_array_cell
    std::cout << std::endl;
}
// c leaves it scope.
// stdout: counter_ptr c is deleted
// stdout: int_array_cell counter 0: deleted
// stdout: counter_ptr b is deleted
