#include <cassert>
#include <iostream>

class DoublyList {
  struct Node {
    int key;
    Node *next = nullptr;
    Node *prev = nullptr;
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
  void swap_node(Node *&a, Node *&b) {
    Node *temp = a;
    a = b;
    b = temp;
  }

public:
  bool is_empty() { return get_size() == 0; }
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
      m_head->prev = new_node;
      m_head = new_node;
    }
  }
  void insert_after_tail(int key) {
    Node *new_node = new Node(key);
    if (get_size() == 0) {
      insert_at_head(key);
    } else {
      new_node->prev = m_tail;
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
      new_node->prev = target_node;
      target_node->next->prev = new_node;
      new_node->next = target_node->next;
      target_node->next = new_node;
    }
  }
  void delete_head() {
    assert(get_size() != 0 && "Can't delete head, linked list is empty");
    Node *deletion_node = m_head;
    Node *new_head = m_head->next;
    if (get_size() == 1) {
      m_tail = nullptr;
    } else {
      new_head->prev = nullptr;
    }
    m_head = new_head;
    delete deletion_node;
  }
  void delete_tail() {
    assert(get_size() != 0 && "Can't delete tail, linked list is empty");
    if (get_size() == 1) {
      delete_head();
    } else {
      Node *deletion_node = m_tail;
      m_tail = m_tail->prev;
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
      deletion_node->next->prev = target_node;
      target_node->next = deletion_node->next;
      delete deletion_node;
    }
  }
  void display() {
    std::cout << "Doubly List(" << get_size() << ") :-\n";
    if (get_size() == 0)
      return;
    std::cout << "\tOriginal: ";
    Node *curr = m_head;
    while (curr != nullptr) {
      std::cout << curr->key;
      if (curr->next == nullptr)
        break;
      std::cout << " -> ";
      curr = curr->next;
    }
    std::cout << "\n\tReverse: ";
    curr = m_tail;
    while (curr != nullptr) {
      std::cout << curr->key;
      if (curr->prev == nullptr)
        break;
      std::cout << " -> ";
      curr = curr->prev;
    }
    std::cout << '\n';
  }
  int search(int key) {
    int index = -1;
    Node *curr = m_head;
    while (curr != nullptr) {
      ++index;
      if (curr->key == key) {
        return index;
      }
      curr = curr->next;
    }
    return -1;
  }
  void reverse() {
    if (is_empty())
      return;
    Node *curr = m_head;
    while (curr != nullptr) {
      swap_node(curr->next, curr->prev);
      curr = curr->prev;
    }
    swap_node(m_head, m_tail);
  }
};

void test_doubly_list() {
  DoublyList ll;
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
  int key = 98;
  std::cout << "Key " << key << " is at index: " << ll.search(key) << '\n';
  ll.reverse();
  std::cout << "After reversing:-\n";
  ll.display();
  ll.reverse();
  std::cout << "After reversing:-\n";
  ll.display();
}

int main() {
  test_doubly_list();
  return 0;
}
