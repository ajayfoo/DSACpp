#include <cassert>
#include <iostream>

class SinglyList {
  struct Node {
    int key;
    Node *next = nullptr;
    Node(int key) { this->key = key; }
  };
  Node *m_head = nullptr;
  Node *m_tail = nullptr;
  Node *get_node_before(int index) {
    Node *curr = m_head;
    int curr_index = 0;
    while (curr_index != index - 1) {
      curr = curr->next;
      ++curr_index;
    }
    return curr;
  }

public:
  int get_size() {
    Node *curr = m_head;
    int size = 0;
    while (curr != nullptr) {
      ++size;
      curr = curr->next;
    }
    return size;
  }
  void insert_at_head(int key) {
    Node *new_node = new Node(key);
    if (get_size() == 0) {
      m_tail = m_head = new_node;
    } else {
      new_node->next = m_head;
      m_head = new_node;
    }
  }
  void insert_after_tail(int key) {
    Node *new_node = new Node(key);
    if (get_size() == 0) {
      m_head = m_tail = new_node;
    } else {
      m_tail->next = new_node;
      m_tail = m_tail->next;
    }
  }
  void insert_at(int index, int key) {
    assert(((index < get_size()) && index > -1) &&
           "Can't insert at an invalid index");
    if (index == 0) {
      insert_at_head(key);
    } else {
      Node *new_node = new Node(key);
      Node *target_node = get_node_before(index);
      new_node->next = target_node->next;
      target_node->next = new_node;
    }
  }
  void delete_head() {
    assert(get_size() != 0 && "Can't delete head, linked list is empty");
    Node *deletion_node = m_head;
    m_head = m_head->next;
    if (get_size() == 0) {
      m_tail = nullptr;
    }
    delete deletion_node;
  }
  void delete_tail() {
    assert(get_size() != 0 && "Can't delete tail, linked list is empty");
    if (get_size() == 1) {
      delete_head();
    } else {
      Node *deletion_node = m_tail;
      m_tail = get_node_before(get_size() - 1);
      m_tail->next = nullptr;
      delete deletion_node;
    }
  }
  void delete_at(int index) {
    assert(((index < get_size()) && index > -1) &&
           "Invalid index, deletion failed");
    if (index == 0) {
      delete_head();
    } else if (index == get_size() - 1) {
      delete_tail();
    } else {
      Node *target_node = get_node_before(index);
      Node *deletion_node = target_node->next;
      target_node->next = deletion_node->next;
      delete deletion_node;
    }
  }
  void display() {
    std::cout << "Singly List(" << get_size() << ") : ";
    if (get_size() == 0)
      return;
    Node *curr = m_head;
    while (curr != m_tail) {
      std::cout << curr->key << " -> ";
      curr = curr->next;
    }
    std::cout << curr->key << '\n';
  }
};

void test_singly_list() {
  SinglyList ll;
  ll.insert_after_tail(33);
  ll.insert_after_tail(3);
  ll.insert_after_tail(2);
  ll.insert_after_tail(43);
  ll.insert_at_head(99);
  ll.insert_at(4, 32);
  ll.display();
  ll.delete_head();
  std::cout << "After deleting head\n";
  ll.display();
  ll.delete_tail();
  std::cout << "After deleting tail\n";
  ll.display();
  ll.delete_at(2);
  std::cout << "After deleting node at index 2\n";
  ll.display();
  ll.insert_at(2, 98);
  std::cout << "After inserting 98 at index 2\n";
  ll.display();
}

int main() {
  test_singly_list();
  return 0;
}
