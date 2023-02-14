#include <cassert>
#include <iostream>

class LinkedList {
  struct Node {
    int key;
    int priority;
    Node *next = nullptr;
    Node(int key, int priority) {
      this->key = key;
      this->priority = priority;
    }
  };
  Node *m_head = nullptr;
  Node *m_tail = nullptr;
  int m_size;
  Node *get_required_node(int priority) {
    Node *curr = m_head;
    while (curr->next != nullptr && curr->next->priority < priority) {
      curr = curr->next;
    }
    if (curr->priority > priority) {
      return nullptr;
    }
    return curr;
  }

public:
  bool is_empty() { return m_size == 0; }
  int get_size() { return m_size; }
  void insert(int key, int priority) {
    Node *new_node = new Node(key, priority);
    if (is_empty()) {
      m_tail = m_head = new_node;
    } else {
      Node *temp_node = get_required_node(priority);
      if (temp_node == nullptr) {
        temp_node = m_head;
        m_head = new_node;
        m_head->next = temp_node;
      } else {
        Node *high_pri_node = temp_node->next;
        temp_node->next = new_node;
        new_node->next = high_pri_node;
      }
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
  void print() {
    Node *curr = m_head;
    while (curr != nullptr) {
      std::cout << "Key: " << curr->key << ", Priority: " << curr->priority
                << '\n';
      curr = curr->next;
    }
  }
};

class LLPriorityQueue {
  LinkedList ll;

public:
  void enqueue(int key, int priority) { ll.insert(key, priority); }
  void dequeue() {
    assert(!ll.is_empty() && "Queue is empty, can't dequeue");
    ll.remove_tail();
  }
  int get_front() {

    assert(!ll.is_empty() && "Queue is empty, retrive front");
    return ll.get_tail();
  }
  void print() {
    std::cout << "Priority Queue:-\n";
    ll.print();
  }
};

void test_linked_list() {
  LinkedList ll;
  ll.insert(10, 8);
  ll.insert(11, 2);
  ll.insert(12, 4);
  ll.insert(13, 1);
  std::cout << "1. Tail: " << ll.get_tail() << '\n';
  std::cout << "1. Size: " << ll.get_size() << '\n';
  ll.remove_tail();
  std::cout << "2. Tail: " << ll.get_tail() << '\n';
  std::cout << "2. Size: " << ll.get_size() << '\n';
}

void test_ll_priority_queue() {
  LLPriorityQueue q;
  q.enqueue(10, 9);
  q.enqueue(11, 1);
  q.enqueue(12, 2);
  q.enqueue(13, 4);
  q.enqueue(17, 1);
  q.print();
  q.enqueue(18, 3);
  q.print();
  std::cout << "1. Front: " << q.get_front() << '\n';
  q.dequeue();
  std::cout << "2. Front: " << q.get_front() << '\n';
}
int main() { test_ll_priority_queue(); }
