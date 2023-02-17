#include "binary_search_tree.h"

void test_binary_search_tree() {
  BinarySearchTree bst;
  bst.insert(9);
  bst.insert(5);
  bst.insert(4);
  bst.insert(10);
  bst.levelorder_traverse();
  std::cout << "Max: " << bst.get_max() << '\n';
  std::cout << "Min: " << bst.get_min() << '\n';
  std::cout << "Total Number of nodes: "
            << BinarySearchTree::get_nodes_count(bst.get_root()) << '\n';
  std::cout << "Total Number of leaf nodes: "
            << BinarySearchTree::get_leaves_count(bst.get_root()) << '\n';
}
int main() {
  test_binary_search_tree();
  return 0;
}
