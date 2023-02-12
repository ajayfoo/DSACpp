#include <cassert>
#include <iostream>
#include <queue>

struct Node {
  int val;
  Node *left;
  Node *right;
  Node(int val, Node *left, Node *right) {
    this->val = val;
    this->left = left;
    this->right = right;
  }
  Node(int val) { this->val = val; }
};
static constexpr int N = 20;
class Queue {
  Node *m_array[N];
  int m_front = -1;
  int m_rear = -2;
  void reset() {
    m_front = -1;
    m_rear = -2;
  }

public:
  int get_length() {
    if (is_empty())
      return 0;
    return (m_rear - m_front) + 1;
  }
  bool is_full() { return m_rear == N - 1; }
  bool is_empty() { return m_front > m_rear; }
  void enqueue(Node *ele) {
    if (is_full()) {
      std::cerr << "Can't enqueue, Queue is full\n";
      return;
    }
    if (is_empty()) {
      ++m_front;
      ++m_rear;
    }
    m_array[++m_rear] = ele;
  }

  void dequeue() {
    if (is_empty()) {
      std::cerr << "Can't dequeue, Queue is empty\n";
      return;
    }
    ++m_front;
    if (is_empty())
      reset();
  }
  Node *get() {
    assert(!is_empty() && "Queue is empty");
    return m_array[m_front];
  }
};
void levelorder_traverse(Node *root) {
  Queue q;
  q.enqueue(root);
  while (!q.is_empty()) {
    Node *current = q.get();
    q.dequeue();
    if (current == nullptr) {
      continue;
    }
    std::cout << current->val << ' ';
    q.enqueue(current->left);
    q.enqueue(current->right);
  }
}

Node *get_dummy_tree() {
  Node *a = new Node(1);
  Node *b = new Node(2);
  Node *c = new Node(3);
  Node *d = new Node(4, nullptr, nullptr);
  Node *e = new Node(5, nullptr, nullptr);
  Node *f = new Node(6, nullptr, nullptr);
  Node *g = new Node(7);
  Node *h = new Node(8, nullptr, nullptr);
  a->left = b;
  a->right = c;
  b->left = d;
  b->right = e;
  c->left = f;
  c->right = g;
  g->left = h;
  return a;
}

void test_bfs() {
  Node *root = get_dummy_tree();
  std::cout << "Postorder Traversal:-\n";
  levelorder_traverse(root);
  std::cout << '\n';
}
int main() {
  test_bfs();
  return 0;
}
