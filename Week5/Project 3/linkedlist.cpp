#include "linkedlist.hpp"

#include <iostream>

void LinkedList::InsertNode(const int value) {
  Node* address = new Node();
  address->value = value;
  address->next = nullptr;
  std::cout << "Insert node working\n";
  if (head_ == nullptr) {
    head_ = address;
    std::cout << "The head: " << head_ << std::endl;

  } else {
    Node* current_node = head_;

    while (current_node->next != nullptr) {
      current_node = current_node->next;
    }
    current_node->next = address;
    std::cout << "Address of second to last node" << current_node << std::endl;
    std::cout << "Address of next in second to last node: "
              << current_node->next << std::endl;
  }
  size_++;
}

void LinkedList::InsertNodeFront(const int value) {
  Node* new_node = new Node();
  new_node->value = value;
  std::cout << "Head_adress" << head_ << std::endl;
  new_node->next = head_;
  head_ = new_node;
  std:: cout << "New Head Address: " << head_ << std::endl << "New Next: " << head_ -> next << std::endl;

  size_++;
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
  first_list.InsertNode(13);
  first_list.InsertNode(15);
  first_list.InsertNode(18);
  first_list.InsertNodeFront(18);
}
