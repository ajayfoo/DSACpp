#ifndef DEQUEUE_H
#define DEQUEUE_H
#include <cassert>
#include <cstddef>
template <typename T, std::size_t N> class Deque {
  T m_array[N];
  int m_front = -1;
  int m_rear = -1;

public:
  bool is_empty() { return m_front == -1; }
  bool is_full() {
    return ((m_front == 0 && m_rear == N - 1) || m_front == m_rear + 1);
  }
  void enqueue_front(T ele) {
    assert(!is_full() && "Can't enqueue, Deque is full");
    if (m_front == -1) {
      m_rear = m_front = 0;
    } else if (m_front == 0) {
      m_front = N - 1;
    } else {
      --m_front;
    }
    m_array[m_front] = ele;
  }
  void enqueue_rear(T ele) {
    assert(!is_full() && "Can't enqueue, Deque is full");
    if (m_front == -1) {
      m_rear = m_front = 0;
    } else if (m_rear == N - 1) {
      m_rear = 0;
    } else {
      ++m_rear;
    }
    m_array[m_rear] = ele;
  }
  void dequeue_front() {
    assert(!is_empty() && "Can't dequeue, Deque is empty");
    if (m_front == m_rear) {
      m_front = -1;
      m_rear = 0;
    } else {
      if (m_front == N - 1) {
        m_front = 0;
      } else {
        ++m_front;
      }
    }
  }
  void dequeue_rear() {
    assert(!is_empty() && "Can't dequeue, Deque is empty");
    if (m_front == m_rear) {
      m_front = -1;
      m_rear = 0;
    } else if (m_rear == 0) {
      m_rear = N - 1;
    } else {
      --m_rear;
    }
  }
  T get_front() { return m_array[m_front]; }
  T get_rear() { return m_array[m_rear]; }
};

#endif
