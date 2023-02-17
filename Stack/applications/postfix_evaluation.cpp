#include <iostream>
#include <stack>
#include <utility>
class PostfixExpression
{
    char* m_expr{};
    int m_len;
    std::stack<int> m_stack{};
    int m_res;
    static bool is_operand(char ele)
    {
        return (ele >= '0' && ele <= '9');
    }
    int get_result(int a, int b, char op)
    {
        int res{};
        switch (op)
        {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            res = a / b;
            break;
        default:
            std::cerr << "Unsupported operator passed\n";
            abort();
        }
        return res;
    }

  public:
    ~PostfixExpression()
    {
        delete[] m_expr;
    }
    void eval()
    {
        for (int i{0}; i < m_len; ++i)
        {
            if (is_operand(m_expr[i]))
            {
                int num = m_expr[i] - '0';
                std::cout << num << '\n';
                m_stack.push(num);
            }
            else
            {
                int b{m_stack.top()};
                m_stack.pop();
                int a{m_stack.top()};
                m_stack.pop();
                char op{m_expr[i]};
                int res = get_result(a, b, op);
                std::cout << a << ' ' << op << ' ' << b;
                std::cout << " = " << res << '\n';
                m_stack.push(res);
            }
        }
        m_res = m_stack.top();
        m_stack.pop();
    }
    void set()
    {
        std::cout << "Postfix expression length: ";
        std::cin >> m_len;
        std::cout << "Enter Postfix expression: ";
        if (m_expr != nullptr)
            delete[] m_expr;
        m_expr = new char[m_len];
        for (int i = 0; i < m_len; ++i)
        {
            std::cin >> m_expr[i];
        }
    }
    void print()
    {
        std::cout << "Postfix expression: ";
        std::cout << m_expr << " = " << m_res << '\n';
        ;
    }
};

int main()
{

    PostfixExpression pexpr;
    pexpr.set();
    pexpr.eval();
    pexpr.print();
    return 0;
}
