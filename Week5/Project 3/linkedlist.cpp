#include "linkedlist.hpp"

#include <iostream>

void LinkedList::InsertNode(const int value) {
  Node* address = new Node();
  address->value = value;
  address->next = nullptr;
  // testing cout
  std::cout << "Insert node working\n";
  if (head_ == nullptr) {
    head_ = address;
    // testing cout
    std::cout << "The head: " << head_ << std::endl;

  } else {
    Node* current_node = head_;

    while (current_node->next != nullptr) {
      current_node = current_node->next;
    }
    current_node->next = address;
    // testing cout
    std::cout << "Address of second to last node" << current_node << std::endl;
    std::cout << "Address of next in second to last node: "
              << current_node->next << std::endl;
  }
  size_++;
}

void LinkedList::InsertNodeFront(const int value) {
  Node* new_node = new Node();
  new_node->value = value;
  // testing cout
  std::cout << "Head_address " << head_ << std::endl;
  new_node->next = head_;
  head_ = new_node;
  // testing cout
  std::cout << "New Head Address: " << head_ << std::endl
            << "New Next: " << head_->next << std::endl;

  size_++;
}

bool LinkedList::Contains(const int value) const {
  Node* current_address = head_;
  while (current_address) {
    if (current_address->value == value) {
      return true;
    }
    current_address = current_address->next;
  }
  return false;
}

bool LinkedList::Remove(const int position) {
  // 1-based position so positions below 1 is out of bounds
  if (position > size_ || position < 1 || head_ == nullptr) {
    return false;
  }

  Node* current_address = head_;

  // If user chooses to delete head
  // updates head to prevent memory leak
  if (position == 1) {
    current_address = head_->next;
    delete head_;
    head_ = current_address;
    return true;
  }

  // Uses previous node to connect it to the node after the deleted one
  int before_position = position - 1;
  Node* before_address = head_;
  // grabs target position address and position before it
  // for relinking
  for (int current_position = 2; current_position <= position;
       current_position++) {
    current_address = current_address->next;

    if (current_position == before_position) {
      before_address = current_address;
    }
  }

  before_address->next = current_address->next;
  delete current_address;

  size_--;
  return true;
}

void LinkedList::Print_Values() const {
  Node* current_address = head_;

  while (current_address) {
    std::cout << current_address -> value;

    if (current_address -> next){
      std::cout << " -> ";
    }

    current_address = current_address -> next;
  }

  std::cout << std::endl;
}

void LinkedList::Print_Addresses() const {
  Node* current_address = head_;
  // 1-based so index starts at 1
  int node_index = 1;

  while (current_address) {
    std::cout << node_index << " " << current_address << " ";
    current_address = current_address -> next;
    node_index++;
  }
  
  std::cout << std::endl;
}

LinkedList::~LinkedList() {
  Node* current_node = head_;
  while (current_node) {
    Node* temp_node = current_node;
    current_node = current_node->next;
    delete temp_node;
  }
  head_ = nullptr;
}

int main() {
  LinkedList first_list;
  bool did_delete = first_list.Remove(3);
  bool did_delete2 = first_list.Remove(0);
  std::cout << "did_delete: " << did_delete << " did_delete2 " << did_delete2 << std::endl;
  bool value_in1 = first_list.Contains(15);
  first_list.InsertNode(13);
  first_list.InsertNode(15);
  first_list.InsertNode(18);
  first_list.InsertNodeFront(18);
  bool value_in2 = first_list.Contains(15);
  bool value_in3 = first_list.Contains(3);
  // testing cout Contains function
  std::cout << "value_in1 expected value false. Actual: " << value_in1
            << "\nvalue_in2 expected value true. Actual: " << value_in2
            << "\nvalue_in3 expected value false. Actual: " << value_in3
            << std::endl;
  first_list.Print_Values();
  first_list.Print_Addresses();
  bool did_delete3 = first_list.Remove(3);
  first_list.Print_Values();
  std::cout << "did_delete3: " << did_delete3 << std::endl;
}
