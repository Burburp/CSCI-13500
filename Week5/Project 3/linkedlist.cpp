#include "linkedlist.hpp"

#include <iostream>

/**
 * Insert node at the end of the linkedlist
 * @param value A const int that you want to store in the node
 */
void LinkedList::InsertNode(const int value) {
  Node* address = new Node();
  address->value = value;
  address->next = nullptr;
  // testing cout
  std::cout << "Insert node working\n";

  // When the inserted note is the first node assign head
  if (head_ == nullptr) {
    head_ = address;
    // testing cout
    std::cout << "The head: " << head_ << std::endl;

  } else {
    Node* current_node = head_;
    // grabs the last node in the list
    while (current_node->next) {
      current_node = current_node->next;
    }
    //
    current_node->next = address;
    // testing cout
    std::cout << "Address of second to last node" << current_node << std::endl;
    std::cout << "Address of next in second to last node: "
              << current_node->next << std::endl;
  }
  size_++;
}

/**
 * Insert Node at the head of the list
 * @param value A const int that you want to store in the node
 */
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

/**
 * Checks if a value exists in the list
 * @param value A const int being checked for in the list
 * @return true if value is found, false otherwise
 */
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

    // Guards against incorrectly tracted size_ of list
    // or memory leaks breaking the list
    if (current_address == nullptr) {
      return false;
    }

    // Grabs the address prior to target
    // to keep list connected
    if (current_position == before_position) {
      before_address = current_address;
    }
  }

  before_address->next = current_address->next;
  delete current_address;

  size_--;
  return true;
}

void LinkedList::PrintValues() const {
  Node* current_address = head_;

  while (current_address) {
    std::cout << current_address->value;

    if (current_address->next) {
      std::cout << " -> ";
    }

    current_address = current_address->next;
  }

  std::cout << std::endl;
}

void LinkedList::PrintAddresses() const {
  Node* current_address = head_;
  // 1-based so index starts at 1
  int node_index = 1;

  while (current_address) {
    std::cout << node_index << " " << current_address << " ";
    current_address = current_address->next;
    node_index++;
  }

  std::cout << std::endl;
}

int LinkedList::GetValueAtPosition(int position) const {
  if (head_ == nullptr || position > size_) {
    throw std::runtime_error("Error: Invalid Position");
  }
  Node* target_address = head_;

  for (int current_pos = 1; current_pos < position; ++current_pos) {
    target_address = target_address->next;
    if (!target_address) {
      throw std::runtime_error("Error: Couldn't find node");
    }
  }

  int target_value = target_address->value;
  return target_value;
}
void LinkedList::InsertNodeAt(const int value, const int position) {
  // Node can be inserted in a position after
  // the existing final node.
  int upper_bound_of_insertion = size_ + 1;
  int lower_bound_of_insertion = 1;

  if (position > upper_bound_of_insertion ||
      position < lower_bound_of_insertion) {
    throw std::runtime_error("Error: Invalid Position");
  }

  if (position == 1) {
    Node* insert_node = new Node;
    insert_node->value = value;
    insert_node->next = head_;
    head_ = insert_node;
  } else {
    // The prior node address and its -> next address
    // alows the new node to be placed between nodes
    Node* prev_node = head_;

    int prev_position = position - 1;
    for (int pos = 1; pos < prev_position; ++pos) {
      if (!prev_node) {
        break;
      }
      prev_node = prev_node->next;
    }

    if (!prev_node) {
      throw std::runtime_error("Error: List Ended Unexpectedly Early");
    }

    Node* insert_node = new Node();
    insert_node->value = value;

    // Patches insert node into the list
    Node* after_node = prev_node->next;
    prev_node->next = insert_node;
    insert_node->next = after_node;
  }

  ++size_;
}

int LinkedList::GetSize() const { return size_; }

LinkedList* LinkedList::ReverseList() {
  LinkedList* new_list = nullptr;
  Node* prev_node = nullptr;
  Node* curr_node = head_;

  // Had to google this
  // Its basically how the node destruction works
  // But with one more pointer
  while (curr_node) {
    Node* next_node = curr_node->next;
    curr_node->next = prev_node;
    prev_node = curr_node;
    curr_node = next_node;
  }
  new_list->head_ = prev_node;
  // This was added after submission
  // Realized there was no return
  // and the destructor destroyed the head and object
  new_list -> size_ = this -> size_;
  this -> head_ = nullptr;
  return new_list;
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

