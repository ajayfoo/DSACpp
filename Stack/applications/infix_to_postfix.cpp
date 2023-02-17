#include <cassert>
#include <cstring>
#include <iostream>

template <typename T, int N> class Stack
{
    T m_array[N];
    int m_top = -1;

  public:
    bool is_empty()
    {
        return m_top == -1;
    }
    bool is_full()
    {
        return m_top == N - 1;
    }
    T peek()
    {
        return m_array[m_top];
    }
    void push(T ele)
    {
        assert(!is_full() && "Stack is full, can't push new element");
        m_array[++m_top] = ele;
    }
    void pop()
    {
        assert(!is_empty() && "Stack is empty, can't pop element");
        --m_top;
    }
    void print()
    {
        std::cout << "Stack: ";
        for (int i = m_top; i >= 0; --i)
        {
            std::cout << m_array[i] << ' ';
        }
        std::cout << '\n';
    }
};

void test_stack()
{
    Stack<char, 5> stack;
    stack.push('A');
    stack.push('B');
    stack.push('D');
    stack.push('E');
    stack.push('F');
    stack.print();
    stack.push('G');
    stack.print();
}

bool is_operand(char tk)
{
    return (tk >= '0' && tk <= '9') || (tk >= 'a' && tk <= 'z') || (tk >= 'A' && tk <= 'Z');
}

int get_prec(char op)
{
    switch (op)
    {
    case '^':
        return 5;
    case '*':
    case '/':
        return 4;
    case '+':
    case '-':
        return 3;
    default:
        assert(false && "Invalid operator passed");
    }
}

bool is_higher_prec(char op1, char op2)
{
    return get_prec(op1) > get_prec(op2);
}

char* infix_to_postfix(char* expr)
{
    Stack<char, 10> stk;
    char* res = new char[strlen(expr)];
    int j = -1;
    for (int i = 0; i < strlen(expr); ++i)
    {
        if (is_operand(expr[i]))
        {
            res[++j] = expr[i];
            continue;
        }
        while (!stk.is_empty() && is_higher_prec(stk.peek(), expr[i]))
        {
            res[++j] = stk.peek();
            stk.pop();
        }
        stk.push(expr[i]);
    }
}

int main()
{
    test_stack();
    return 0;
}
