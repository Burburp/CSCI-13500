#include "linkedlist.hpp"
#include <iostream>

int main() {
  LinkedList first_list;

  // Attempt to remove position in empty list
  bool did_delete = first_list.Remove(3);
  bool did_delete2 = first_list.Remove(1);
  std::cout << "did_delete: " << did_delete << " did_delete2 " << did_delete2
            << std::endl;
  // check for a value in an empty list
  bool value_in1 = first_list.Contains(15);

  // add a few values to list
  first_list.InsertNode(13);
  first_list.InsertNode(15);
  first_list.InsertNode(18);
  // add value to front of list
  first_list.InsertNodeFront(18);

  // check for a value that exists and one that doesnt using Contains
  bool value_in2 = first_list.Contains(15);
  bool value_in3 = first_list.Contains(3);
  // testing cout Contains function
  std::cout << "value_in1 expected value false. Actual: " << value_in1
            << "\nvalue_in2 expected value true. Actual: " << value_in2
            << "\nvalue_in3 expected value false. Actual: " << value_in3
            << std::endl;
  // Check if list matches with earlier changes
  first_list.PrintValues();
  first_list.PrintAddresses();

  // remove a value that does exist and check changes
  bool did_delete3 = first_list.Remove(3);
  first_list.PrintValues();
  std::cout << "did_delete3: " << did_delete3 << std::endl;

  int size_1 = first_list.GetSize();
  std::cout << size_1 << std::endl;
  try {
    std::cout << first_list.GetValueAtPosition(3) << std::endl
              << first_list.GetValueAtPosition(4) << std::endl;
  } catch (const std::runtime_error& error_message) {
    std::cout << error_message.what() << std::endl;
  }
  first_list.InsertNodeAt(37, 4);
  first_list.InsertNodeAt(23, 3);
  first_list.InsertNodeAt(1, 1);
  try {
    first_list.InsertNodeAt(9, 8);
  } catch (std::runtime_error& error_message) {
    std::cout << error_message.what() << std::endl;
  }
  first_list.PrintValues();
}
