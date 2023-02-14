#include <cassert>
#include <iostream>
static constexpr int MAX_SIZE = 3;
class IntHeap {
  int m_size = 0;
  int m_heap[MAX_SIZE];
  static void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
  }
  static int parent(int i) { return (i - 1) / 2; }
  static int left_child(int i) { return (2 * i) + 1; }
  static int right_child(int i) { return (2 * i) + 2; }
  void sift_down(int i) {
    int max_i = i;
    int l = left_child(i);
    if (l <= m_size && (m_heap[l] > m_heap[max_i])) {
      max_i = l;
    }
    int r = right_child(i);
    if (r <= m_size && (m_heap[r] > m_heap[max_i])) {
      max_i = r;
    }
    if (max_i != i) {
      swap(m_heap[i], m_heap[max_i]);
      sift_down(max_i);
    }
  }
  void sift_up(int i) {
    while ((i > 0) && (m_heap[i] > m_heap[parent(i)])) {
      swap(m_heap[i], m_heap[parent(i)]);
      i = parent(i);
    }
  }

public:
  bool is_full() { return m_size == MAX_SIZE; }
  bool is_empty() { return m_size == 0; }
  void insert(int ele) {
    assert(!is_full() && "Heap is full, can't insert a new element!");
    m_heap[m_size] = ele;
    sift_up(m_size);
    ++m_size;
  }
  int get_max() { return m_heap[0]; }
  int extract_max() {
    assert(!is_empty() && "Heap is empty, can't extract max element!");
    int max_ele = get_max();
    m_heap[0] = m_heap[m_size - 1];
    sift_down(0);
    --m_size;
    return max_ele;
  }
  void print() {
    if (is_empty())
      return;
    std::cout << "Heap: ";
    for (int i = 0; i < m_size; ++i) {
      std::cout << m_heap[i] << ' ';
    }
    std::cout << '\n';
  }
};

void test_heap() {
  IntHeap heap;
  heap.insert(3);
  heap.insert(8);
  heap.insert(10);
  heap.print();
  heap.insert(11);
  heap.print();
  std::cout << "Extracted element: " << heap.extract_max() << '\n';
  std::cout << "Extracted element: " << heap.extract_max() << '\n';
  std::cout << "Extracted element: " << heap.extract_max() << '\n';
  std::cout << "Extracted element: " << heap.extract_max() << '\n';
  std::cout << "Extracted element: " << heap.extract_max() << '\n';
  heap.print();
}

int main() {
  test_heap();
  return 0;
}
