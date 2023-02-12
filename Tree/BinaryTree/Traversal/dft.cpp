#include <iostream>

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

void preorder_traverse(Node *root) {
  if (root == nullptr)
    return;
  std::cout << root->val << ' ';
  preorder_traverse(root->left);
  preorder_traverse(root->right);
}
void inorder_traverse(Node *root) {
  if (root == nullptr)
    return;
  inorder_traverse(root->left);
  std::cout << root->val << ' ';
  inorder_traverse(root->right);
}
void postorder_traverse(Node *root) {
  if (root == nullptr)
    return;
  postorder_traverse(root->left);
  postorder_traverse(root->right);
  std::cout << root->val << ' ';
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

void test_traversals() {
  Node *root = get_dummy_tree();
  std::cout << "Preorder Traversal:-\n";
  preorder_traverse(root);
  std::cout << '\n';
  std::cout << "Inorder Traversal:-\n";
  inorder_traverse(root);
  std::cout << '\n';
  std::cout << "Postorder Traversal:-\n";
  postorder_traverse(root);
  std::cout << '\n';
}
int main() {
  test_traversals();
  return 0;
}
