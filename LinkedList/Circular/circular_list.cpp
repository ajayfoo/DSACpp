#include <cassert>
#include <iostream>

class CircularList {
  struct Node {
    int key;
    Node *next = nullptr;
    Node(int key) { this->key = key; }
  };
  Node *m_tail = nullptr;
  Node *get_node_before(int index) {
    Node *curr = m_tail->next;
    int curr_index = 0;
    do {
      curr = curr->next;
      ++curr_index;
    } while (curr_index != index - 1);
    return curr;
  }

public:
  bool is_empty() { return get_size() == 0; }
  int get_size() {
    if (m_tail == nullptr) {
      return 0;
    }
    Node *curr = m_tail->next;
    int size = 0;
    do {
      ++size;
      curr = curr->next;
    } while (curr != m_tail->next);
    return size;
  }
  void insert_at_head(int key) {
    Node *new_node = new Node(key);
    if (get_size() == 0) {
      m_tail = new_node;
      m_tail->next = m_tail;
    } else {
      new_node->next = m_tail->next;
      m_tail->next = new_node;
    }
  }
  void insert_after_tail(int key) {
    Node *new_node = new Node(key);
    if (get_size() == 0) {
      insert_at_head(key);
    } else {
      Node *head = m_tail->next;
      m_tail->next = new_node;
      m_tail = m_tail->next;
      m_tail->next = head;
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
    Node *deletion_node = m_tail->next;
    if (get_size() == 1) {
      m_tail = nullptr;
    } else {
      m_tail->next = deletion_node->next;
    }
    delete deletion_node;
  }
  void delete_tail() {
    assert(get_size() != 0 && "Can't delete tail, linked list is empty");
    if (get_size() == 1) {
      delete_head();
    } else {
      Node *head = m_tail->next;
      Node *deletion_node = m_tail;
      m_tail = get_node_before(get_size() - 1);
      m_tail->next = head;
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
    std::cout << "Circular List(" << get_size() << ") : ";
    if (get_size() == 0)
      return;
    Node *curr = m_tail->next;
    do {
      std::cout << curr->key << " -> ";
      curr = curr->next;
    } while (curr != m_tail->next);
    std::cout << '\n';
  }
  int search(int key) {
    int index = -1;
    Node *curr = m_tail->next;
    do {
      ++index;
      if (curr->key == key) {
        return index;
      }
      curr = curr->next;
    } while (curr != m_tail->next);
    return -1;
  }
  void reverse() {
    Node *head = m_tail->next;
    Node *prev = m_tail;
    Node *curr = m_tail->next;
    Node *next = nullptr;
    do {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    } while (curr != head);
    m_tail = head;
  }
};

void test_circular_list() {
  CircularList ll;
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
  test_circular_list();
  return 0;
}
