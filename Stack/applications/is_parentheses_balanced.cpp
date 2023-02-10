#include <iostream>
#include <stack>

bool is_opn_prth(char prth) {
  switch (prth) {
  case '{':
  case '[':
  case '(':
    return true;
  default:
    return false;
  }
}

bool is_clo_prth(char prth) {
  switch (prth) {
  case '}':
  case ']':
  case ')':
    return true;
  default:
    return false;
  }
}
char get_opn_prth(char prth) {
  switch (prth) {
  case '}':
    return '{';
  case ']':
    return '[';
  case ')':
    return '(';
  default:
    return ' ';
  }
}
bool is_prth(char prth) {
  if (!is_opn_prth(prth) && !is_clo_prth(prth)) {
    return false;
  }
  return true;
}

bool is_prth_balanced(char *expr, int n) {
  std::stack<char> stk;
  for (int i = 0; i < n; ++i) {
    if (!is_prth(expr[i])) {
      continue;
    }
    if (is_clo_prth(expr[i]) && stk.empty()) {
      return false;
    }
    if (is_opn_prth(expr[i])) {
      stk.push(expr[i]);
    }
    if (is_clo_prth(expr[i])) {

      if (stk.top() != get_opn_prth(expr[i])) {
        return false;
      }
      stk.pop();
    }
  }
  return stk.empty();
}
int set_expr(char *&expr) {
  int len = 0;
  std::cout << "Enter expression length: ";
  std::cin >> len;
  std::cout << "Enter expression: ";
  if (expr != nullptr)
    delete[] expr;
  expr = new char[len];
  for (int i = 0; i < len; ++i) {
    std::cin >> expr[i];
  }
  return len;
}
void print(char *expr, bool res) {
  std::cout << "Expression ";
  std::cout << expr << " is ";
  std::cout << (res ? "" : "not") << " balanced\n";
  ;
}

int main() {
  char *expr = nullptr;
  int len = set_expr(expr);
  bool res = is_prth_balanced(expr, len);
  print(expr, res);
  return 0;
}
