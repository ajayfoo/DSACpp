#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <cassert>
#include <iostream>
#include <queue>

class BinarySearchTree {
  struct Node {
    int val;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int val) { this->val = val; }
  };
  Node *m_root = nullptr;

public:
  bool is_empty() { return m_root == nullptr; }
  void insert(int val) {
    if (m_root == nullptr) {
      m_root = new Node(val);
      return;
    }
    Node *prev = m_root;
    Node *curr = m_root;
    while (curr != nullptr) {
      prev = curr;
      if (m_root->val == val)
        return;
      if (val <= m_root->val) {
        curr = curr->left;
      } else {
        curr = curr->right;
      }
    }
    if (val <= prev->val) {
      prev->left = new Node(val);
    } else {
      prev->right = new Node(val);
    }
  }
  void levelorder_traverse() {
    std::queue<Node *> q;
    q.push(m_root);
    while (!q.empty()) {
      Node *current = q.front();
      q.pop();
      if (current == nullptr) {
        continue;
      }
      std::cout << current->val << ' ';
      q.push(current->left);
      q.push(current->right);
    }
    std::cout << '\n';
  }
  int get_max() {
    assert(!is_empty() && "Tree is empty can't get max");
    Node *curr = m_root;
    while (curr->right != nullptr) {
      curr = curr->right;
    }
    return curr->val;
  }
  int get_min() {
    assert(!is_empty() && "Tree is empty can't get min");
    Node *curr = m_root;
    while (curr->left != nullptr) {
      curr = curr->left;
    }
    return curr->val;
  }
  Node *get_root() { return m_root; }
  static int get_nodes_count(Node *root) {
    if (root == nullptr)
      return 0;
    int l = get_nodes_count(root->left);
    int r = get_nodes_count(root->right);
    return 1 + l + r;
  }
  static int get_leaves_count(Node *root) {
    if (root == nullptr) {
      return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return 1;
    } else {
      return get_leaves_count(root->left) + get_leaves_count(root->right);
    }
  }
};

#endif
