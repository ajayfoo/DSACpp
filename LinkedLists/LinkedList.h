#include <initializer_list>
#include <iostream>
#include <memory>

namespace ds_impl {
class LinkedList {
  struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  std::unique_ptr<ListNode> m_head{};
  std::unique_ptr<ListNode> m_tail{};
  std::size_t m_length{0};

public:
  LinkedList(std::initializer_list<int> list) : m_length{list.size()} {
    if (m_length >= 1) {
      insert_at_head(*list.begin());
      if (m_length > 1) {
        insert_after_tail((*(list.begin() + 1)));
      }
      return;
    }
    for (int i{0}; auto ele : list) {
      if (i > 1) {
        insert_after_tail(ele);
      } else {
        ++i;
      }
    }
  }
  void insert_at_head(int val) {
    m_head = std::make_unique<ListNode>(val, m_head.get());
    ++m_length;
  }
  void insert_after_tail(int val) {
    auto new_node = std::make_unique<ListNode>(val);
    m_tail->next = new_node.get();
    m_tail = std::move(new_node);
    ++m_length;
  }
  void print() {
    std::cout << "LinkedList: ";
    ListNode *current_node{m_head.get()};
    while (current_node != nullptr) {
      std::cout << current_node->val << ' ';
      current_node = current_node->next;
    }
  }
};

} // namespace ds_impl
