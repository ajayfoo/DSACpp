#include <iostream>

class Polynomial {
  class Term {
    int abs(int num) {
      if (num < 0)
        return num * -1;
      return num;
    }

  public:
    int coeff;
    int exp;
    char var;
    Term *next = nullptr;
    Term(int coeff, int exp, char var = 'x') {
      this->coeff = coeff;
      this->exp = exp;
      this->var = var;
    }
    void print(bool is_first) {
      char plus = is_first ? ' ' : '+';
      std::cout << (coeff > 0 ? plus : '-') << ' ';
      std::cout << abs(coeff);
      std::cout << var << '^' << exp << ' ';
    }
  };
  Term *m_first;
  Term *m_last;

public:
  Term *get_first() { return m_first; }
  void insert(int coeff, int exp, char var = 'x') {
    if (m_first == nullptr) {
      m_last = m_first = new Term(coeff, exp, var);
    } else {
      m_last->next = new Term(coeff, exp, var);
      m_last = m_last->next;
    }
  }
  void insert(Term *term) {
    if (m_first == nullptr) {
      m_last = m_first = term;
    } else {
      m_last->next = term;
      while (m_last->next != nullptr) {
        m_last = m_last->next;
      }
    }
  }
  void print() {
    Term *curr = m_first;
    std::cout << "Polynomial:";
    while (curr != nullptr) {
      curr->print(curr == m_first);
      curr = curr->next;
    }
    std::cout << '\n';
  }
  static Polynomial *add(Polynomial *poly1, Polynomial *poly2) {
    Polynomial *poly = new Polynomial();
    Term *walker1 = poly1->get_first();
    Term *walker2 = poly2->get_first();
    while (walker1 != nullptr && walker2 != nullptr) {
      if (walker1->exp == walker2->exp) {
        poly->insert(walker1->coeff + walker2->coeff, walker1->exp);
        walker1 = walker1->next;
        walker2 = walker2->next;
        continue;
      }
      if (walker1->exp > walker2->exp) {
        poly->insert(walker1->coeff, walker1->exp);
        walker1 = walker1->next;
      } else {
        poly->insert(walker2->coeff, walker2->exp);
        walker2 = walker2->next;
      }
    }
    if (walker1 != nullptr) {
      poly->insert(walker1);
    }
    if (walker2 != nullptr) {
      poly->insert(walker2);
    }
    return poly;
  }
};

void test_polynomial() {
  Polynomial *poly1 = new Polynomial();
  poly1->insert(5, 6);
  poly1->insert(6, 4);
  poly1->insert(2, 3);
  poly1->print();
  Polynomial *poly2 = new Polynomial();
  poly2->insert(8, 6);
  poly2->insert(3, 2);
  poly2->insert(4, 1);
  poly2->insert(5, 0);
  poly2->print();
  Polynomial *poly = Polynomial::add(poly1, poly2);
  std::cout << "Polynomial 1 + Poylynomial 2 :-\n";
  poly->print();
}
int main() {
  test_polynomial();
  return 0;
}
