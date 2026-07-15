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

/**
 *
 */
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
    insert_node -> value = value;
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
