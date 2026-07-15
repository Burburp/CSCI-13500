#include <iostream>

int main() {
    int number = 42;
    int* pointer = &number;

    std::cout << "Value of number: " << number << std::endl;
    std::cout << "Adress of number: " << pointer << std::endl;
    std::cout << "Value through pointer: " << *pointer << std::endl;
    return 0;

}