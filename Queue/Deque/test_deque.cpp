#include "Deque.h"
#include <iostream>
void test_deque() {
  Deque<int, 3> deq;
  deq.enqueue_front(99);
  std::cout << "Front: " << deq.get_front() << '\n';
  std::cout << "Rear: " << deq.get_rear() << '\n';
  deq.enqueue_rear(8);
  std::cout << "Front: " << deq.get_front() << '\n';
  std::cout << "Rear: " << deq.get_rear() << '\n';
  deq.enqueue_front(19);
  std::cout << "Front: " << deq.get_front() << '\n';
  std::cout << "Rear: " << deq.get_rear() << '\n';
  deq.dequeue_rear();
  deq.dequeue_rear();
  std::cout << "Front: " << deq.get_front() << '\n';
  std::cout << "Rear: " << deq.get_rear() << '\n';
  deq.dequeue_rear();
  deq.dequeue_rear();
}

int main() {
  test_deque();
  return 0;
}
