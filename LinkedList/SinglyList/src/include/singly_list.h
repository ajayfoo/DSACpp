
#ifndef DS_IMPL_SINGLY_LIST_H
#define DS_IMPL_SINGLY_LIST_H

#include <cassert>
#include <iostream>

namespace ds_impl
{
class SinglyList
{
    struct Node
    {
        int key;
        Node* next = nullptr;
        Node(int k) { this->key = k; }
    };
    Node* m_head = nullptr;
    Node* m_tail = nullptr;
    auto get_node_before(int index) -> Node*
    {
        Node* curr = m_head;
        int curr_index = 0;
        while (curr_index != index - 1)
        {
            curr = curr->next;
            ++curr_index;
        }
        return curr;
    }

  public:
    auto is_empty() -> bool { return get_size() == 0; }
    auto get_size() -> int
    {
        Node* curr = m_head;
        int size = 0;
        while (curr != nullptr)
        {
            ++size;
            curr = curr->next;
        }
        return size;
    }
    auto insert_at_head(int key)
    {
        Node* new_node = new Node(key);
        if (get_size() == 0)
        {
            m_tail = m_head = new_node;
        }
        else
        {
            new_node->next = m_head;
            m_head = new_node;
        }
    }
    auto insert_after_tail(int key)
    {
        Node* new_node = new Node(key);
        if (get_size() == 0)
        {
            m_head = m_tail = new_node;
        }
        else
        {
            m_tail->next = new_node;
            m_tail = m_tail->next;
        }
    }
    auto insert_at(int index, int key)
    {
        assert(((index < get_size()) && index > -1) &&
               "Can't insert at an invalid index");
        if (index == 0)
        {
            insert_at_head(key);
        }
        else
        {
            Node* new_node = new Node(key);
            Node* target_node = get_node_before(index);
            new_node->next = target_node->next;
            target_node->next = new_node;
        }
    }
    auto delete_head()
    {
        assert(get_size() != 0 && "Can't delete head, linked list is empty");
        Node* deletion_node = m_head;
        m_head = m_head->next;
        if (get_size() == 0)
        {
            m_tail = nullptr;
        }
        delete deletion_node;
    }
    auto delete_tail()
    {
        assert(get_size() != 0 && "Can't delete tail, linked list is empty");
        if (get_size() == 1)
        {
            delete_head();
        }
        else
        {
            Node* deletion_node = m_tail;
            m_tail = get_node_before(get_size() - 1);
            m_tail->next = nullptr;
            delete deletion_node;
        }
    }
    auto delete_at(int index)
    {
        assert(((index < get_size()) && index > -1) &&
               "Invalid index, deletion failed");
        if (index == 0)
        {
            delete_head();
        }
        else if (index == get_size() - 1)
        {
            delete_tail();
        }
        else
        {
            Node* target_node = get_node_before(index);
            Node* deletion_node = target_node->next;
            target_node->next = deletion_node->next;
            delete deletion_node;
        }
    }
    auto display()
    {
        std::cout << "Singly List(" << get_size() << ") : ";
        if (get_size() == 0)
            return;
        Node* curr = m_head;
        while (curr != m_tail)
        {
            std::cout << curr->key << " -> ";
            curr = curr->next;
        }
        std::cout << curr->key << '\n';
    }
    int search(int key)
    {
        int index = -1;
        Node* curr = m_head;
        while (curr != nullptr)
        {
            ++index;
            if (curr->key == key)
            {
                return index;
            }
            curr = curr->next;
        }
        return -1;
    }
    auto reverse()
    {
        Node* curr = m_head;
        Node* prev = nullptr;
        Node* next = nullptr;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        m_tail = m_head;
        m_head = prev;
    }
};

} // namespace ds_impl

#endif
