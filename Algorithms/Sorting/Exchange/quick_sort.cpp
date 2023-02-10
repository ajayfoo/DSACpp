#include <iostream>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition_and_get_pindex(int arr[], int start, int end) {
  int &pivot{arr[end]};
  int pindex{start};
  int walker{};
  // 7,8,10,9,11,2,7
  for (walker = start; walker < end; ++walker) {
    if (arr[walker] <= pivot) {
      swap(&arr[walker], &arr[pindex]);
      ++pindex;
    }
  }
  swap(&arr[pindex], &pivot);
  return pindex;
}

void quick_sort(int arr[], int start, int end) {
  if (start >= end)
    return;
  int part_index{partition_and_get_pindex(arr, start, end)};
  quick_sort(arr, start, part_index - 1);
  quick_sort(arr, part_index + 1, end);
}
void print_arr(int arr[], int n) {
  std::cout << "Array: ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}
void test_quick_sort() {
  constexpr int N{19};
  int arr[N] = {8, 4, 2, 9, 5, 4, 1, 4, 5, 3, 8, 7, 16, 19, 9, 17, 20, 12};
  print_arr(arr, N);
  quick_sort(arr, 0, N - 1);
  print_arr(arr, N);
}

int main() {
  test_quick_sort();
  return 0;
}
