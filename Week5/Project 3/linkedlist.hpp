#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

struct Node {
  int value;
  Node* next;
};

class LinkedList {
  public:
  void InsertNode(const int value);
  void InsertNodeFront(const int val);
  bool Contains(const int value) const;
  ~LinkedList();

  private:
    int size_ = 0;
    Node* head_ = nullptr;
};

#endif