#include <cassert>
#include <iostream>

class LinkedList {
  struct Node {
    int key;
    Node *next = nullptr;
    Node(int key) { this->key = key; }
    Node(int key, Node *next) {
      this->key = key;
      this->next = next;
    }
  };
  Node *m_head = nullptr;
  Node *m_tail = nullptr;
  int m_size;

public:
  bool is_empty() { return m_size == 0; }
  int get_size() { return m_size; }
  void insert_at_head(int key) {
    Node *new_node = new Node(key, nullptr);
    if (is_empty()) {
      m_tail = m_head = new_node;
    } else {
      Node *prev_head = m_head;
      m_head = new_node;
      m_head->next = prev_head;
    }
    ++m_size;
  }
  void remove_tail() {
    assert(!is_empty() && "LinkedList is empty, can't remove tail");
    Node *curr = m_head;
    while (curr->next != m_tail) {
      curr = curr->next;
    }
    Node *deletion_node = m_tail;
    m_tail = curr;
    m_tail->next = nullptr;
    delete deletion_node;
    --m_size;
  }
  int get_tail() {
    assert(!is_empty() && "LinkedList is empty, can't retrieve tail");
    return m_tail->key;
  }
};

class LLSimpleQueue {
  LinkedList ll;

public:
  void enqueue(int key) { ll.insert_at_head(key); }
  void dequeue() {
    assert(!ll.is_empty() && "Queue is empty, can't dequeue");
    ll.remove_tail();
  }
  int get_front() {

    assert(!ll.is_empty() && "Queue is empty, retrive front");
    return ll.get_tail();
  }
};

void test_linked_list() {
  LinkedList ll;
  ll.insert_at_head(10);
  ll.insert_at_head(11);
  ll.insert_at_head(12);
  ll.insert_at_head(13);
  std::cout << "1. Tail: " << ll.get_tail() << '\n';
  std::cout << "1. Size: " << ll.get_size() << '\n';
  ll.remove_tail();
  std::cout << "2. Tail: " << ll.get_tail() << '\n';
  std::cout << "2. Size: " << ll.get_size() << '\n';
}

void test_ll_simple_queue() {
  LLSimpleQueue q;
  q.enqueue(10);
  q.enqueue(11);
  q.enqueue(12);
  q.enqueue(13);
  q.enqueue(17);
  std::cout << "1. Front: " << q.get_front() << '\n';
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.dequeue();
  std::cout << "2. Front: " << q.get_front() << '\n';
  q.dequeue();
  q.dequeue();
}
int main() { test_ll_simple_queue(); }
