#include <cassert>
#include <iostream>

static constexpr int N = 5;
class Queue {
  int m_array[N];
  int m_front = -1;
  int m_rear = -1;
  void reset() {
    m_front = -1;
    m_rear = -1;
  }

public:
  int get_length() {
    if (is_empty())
      return 0;
    return (m_rear - m_front) + 1;
  }
  bool is_full() { return m_rear == N - 1; }
  bool is_empty() { return m_front == -1 && m_rear == -1; }
  void enqueue(int ele) {
    if (is_full()) {
      std::cerr << "Can't enqueue, Queue is full\n";
      return;
    }
    if (is_empty()) {
      m_front = 0;
    }
    m_array[++m_rear] = ele;
  }

  void dequeue() {
    if (is_empty()) {
      std::cerr << "Can't dequeue, Queue is empty\n";
      return;
    }
    if (m_front == m_rear)
      reset();
    else {
      ++m_front;
    }
  }
  int get() {
    assert(!is_empty() && "Queue is empty");
    return m_array[m_front];
  }
};

int main() {
  Queue q;
  q.enqueue(7);
  q.enqueue(8);
  q.enqueue(9);
  q.enqueue(10);
  std::cout << "Length: " << q.get_length() << '\n';
  std::cout << "Front: " << q.get() << '\n';
  q.dequeue();
  q.dequeue();
  q.dequeue();

  std::cout << "Length: " << q.get_length() << '\n';
  std::cout << "Front: " << q.get() << '\n';
  q.dequeue();
  std::cout << "Length: " << q.get_length() << '\n';
  q.enqueue(11);
  q.enqueue(12);
  q.enqueue(13);
  q.enqueue(14);
  q.enqueue(15);
  std::cout << "Length: " << q.get_length() << '\n';
  std::cout << "Front: " << q.get() << '\n';
  q.enqueue(16);
}
