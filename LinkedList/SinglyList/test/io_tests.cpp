
#include "singly_list.h"
#include <iostream>

void test_singly_list() {
  ds_impl::SinglyList ll;
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

auto main() -> int {
  test_singly_list();
  return 0;
}