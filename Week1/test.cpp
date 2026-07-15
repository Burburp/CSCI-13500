#include <iostream>
#include <string>

int main(){


int age = 0;
std::string name = "";

std::cout << "Please enter your name: ";
std::cin >> name;

std::cout << "Please enter your age: ";
std::cin >> age;

std::cout << "Your name is " << name << std::endl << "Your age is " << age << std::endl;

return 0;


}
