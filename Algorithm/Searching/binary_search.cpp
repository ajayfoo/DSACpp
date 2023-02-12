#include <iostream>
#include <tuple>
#include <vector>

using std::size_t;
using std::vector;

int binary_search(const vector<int> &nums, int target) {
  int starti{0};
  int endi{static_cast<int>(nums.size()) - 1};
  while (starti <= endi) {
    int midi{(starti + endi) / 2};
    if (nums[midi] == target) {
      return midi;
    } else if (nums[midi] < target) {
      starti = midi + 1;
    } else {
      endi = midi - 1;
    }
  }
  return -1;
}
void print_vec(const vector<int> &vec, std::string_view msg) {
  std::cout << msg << ": ";
  for (auto ele : vec) {
    std::cout << ele << ' ';
  }
  std::cout << '\n';
}
void test_binary_search() {
  using dummy_t = std::tuple<vector<int>, int, int>;
  vector<dummy_t> dummies{dummy_t{{1, 2, 4, 9}, 9, 3},
                          dummy_t{{1, 2, 4, 9}, 1, 0},
                          dummy_t{{1, 3, 5, 6}, 3, 1},
                          dummy_t{{2, 3, 5, 6}, 0, -1},
                          dummy_t{{2, 3, 5, 6}, 8, -1},
                          dummy_t{{1, 3, 6, 9, 45}, 1, 0},
                          dummy_t{{1, 3, 6, 9, 45}, 3, 1},
                          dummy_t{{1, 3, 6, 9, 45}, 9, 3},
                          dummy_t{{1, 3, 6, 9, 45}, 6, 2},
                          dummy_t{{1, 3, 6, 9, 45}, 45, 4},
                          dummy_t{{1, 3, 6, 9, 45}, 85, -1},
                          dummy_t{{1, 3, 6, 9, 45}, 0, -1},
                          dummy_t{{1, 3, 5, 6, 56, 78, 89}, 3, 1},
                          dummy_t{{1, 3, 5, 6, 56, 78, 89}, 5, 2},
                          dummy_t{{1, 3, 5, 6, 56, 78, 89}, 78, 5}};
  for (const auto &dummy : dummies) {
    const vector<int> nums{std::get<0>(dummy)};
    const int target{std::get<1>(dummy)};
    std::cout << std::boolalpha;
    int pos{binary_search(nums, target)};

    std::cout << "Test Result: ";
    const bool result{(pos == std::get<2>(dummy))};
    std::cout << (result ? "Passed" : "Failed") << '\n';
    print_vec(nums, "Array");
    std::cout << "Element to find: " << std::get<1>(dummy) << '\n';
    std::cout << "Position: " << pos << '\n';
  }
}
int main() {
  test_binary_search();
  return 0;
}
