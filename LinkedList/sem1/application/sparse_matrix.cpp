#include <iostream>

static constexpr int ROWN = 3;
static constexpr int COLN = 3;

class SparseMatrix {
  struct Cell {
    int row;
    int col;
    int ele;
    Cell *next = nullptr;
    Cell(int row, int col, int ele) {
      this->row = row;
      this->col = col;
      this->ele = ele;
    }
    void print() {
      std::cout << "cell[" << row << "][" << col << "]: " << ele << '\n';
    }
  };
  Cell *m_head;
  Cell *m_tail;
  void insert(int row, int col, int ele) {
    Cell *new_cell = new Cell(row, col, ele);
    if (m_head == nullptr) {
      m_tail = m_head = new_cell;
      return;
    }
    ++m_head->ele;
    m_tail->next = new_cell;
    m_tail = m_tail->next;
  }
  int get_size() {
    Cell *curr = m_head;
    int size = -1;
    while (curr != nullptr) {
      curr = curr->next;
      ++size;
    }
    return size;
  }

public:
  SparseMatrix(int rown, int coln) { insert(rown, coln, 0); }
  void print() {
    std::cout << "Sparse Matrix(" << m_head->row << 'x' << m_head->col << "): ";
    std::cout << "Non Zero Cells: " << m_head->ele << '\n';
    Cell *curr = m_head->next;
    while (curr != nullptr) {
      curr->print();
      curr = curr->next;
    }
  }
  static SparseMatrix *create(int rown, int coln, int mat[ROWN][COLN]) {
    SparseMatrix *smat = new SparseMatrix(rown, coln);
    for (int i = 0; i < rown; ++i) {
      for (int j = 0; j < coln; ++j) {
        if (mat[i][j] != 0) {
          smat->insert(i, j, mat[i][j]);
        }
      }
    }
    return smat;
  }
};

void test_sparse_matrix() {
  int mat[ROWN][COLN] = {{0, 0, 1}, {0, 0, 0}, {1, 0, 0}};
  SparseMatrix *smat = SparseMatrix::create(ROWN, COLN, mat);
  smat->print();
}

int main() {
  test_sparse_matrix();
  return 0;
}
