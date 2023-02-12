#include <iostream>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void shell_sort(int arr[], int n) {
  int curr{};
  int walker{};
  int hold{};
  int num_shifts{0};
  int num_swaps{0};
  for (int incr{n / 2}; incr > 0; incr /= 2) {
    for (curr = 0; curr < (n - incr); curr += incr) {
      hold = arr[curr + incr];
      // find the hole and shift
      for (walker = curr; (walker >= 0) && (arr[walker] < hold);
           walker -= incr) {
        arr[walker + incr] = arr[walker];
        ++num_shifts;
      }
      swap(&arr[walker + incr], &hold);
      ++num_swaps;
    }
  }
  std::cout << "Number of shifts: " << num_shifts << '\n';
  std::cout << "Number of swaps: " << num_swaps << '\n';
}
void print_arr(int arr[], int n) {
  std::cout << "Array: ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}
void test_shell_sort() {
  constexpr int N{19};
  int arr[N] = {8, 4, 2, 9, 5, 4, 1, 4, 5, 3, 8, 7, 16, 19, 9, 17, 20, 12};
  print_arr(arr, N);
  shell_sort(arr, N);
  print_arr(arr, N);
}

int main() {
  test_shell_sort();
  return 0;
}
