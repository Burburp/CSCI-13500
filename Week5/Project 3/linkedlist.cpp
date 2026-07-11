#include <linkedlist.hpp>
#include <iostream>

void LinkedList::InsertNode(const int value) {
  Node* address = new Node();
  address->value = value;
  address->next = nullptr;

  if (head_ = nullptr) {
    head_ = address;
    std::cout << "The head: " << head_ << std::endl;
  } else {
    Node* current_node = head_;
    

    while (current_node->next != nullptr) {
      current_node = current_node->next;
    }
    current_node->next = address;
    std::cout << "Address of second to last note" << current_node << std::endl;
    std::cout << "Address of next in second to last node: " << current_node -> next << std::endl;
  }
  size_++;
}

LinkedList::~LinkedList(){
  Node* current_node = head_;
  while(current_node -> next != nullptr){
    
  }
}

int main(){
  LinkedList first_list = LinkedList();
  first_list.InsertNode(13);
}
