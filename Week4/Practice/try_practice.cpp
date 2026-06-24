#include <iostream>
#include <vector>

int main() {
  try {
    std::vector<int> v = {1, 2, 3};
    std::cout << v.at(10);
  } catch (const std::out_of_range& e) {
    std::cout << "Invalid index!";
  }
  return 0;
}