#include <iostream>

int get_smallest_elei(int arr[], int start, int size) {
  int smallest_elei{start};
  for (int i{start}; i < size; ++i) {
    if (arr[smallest_elei] > arr[i]) {
      smallest_elei = i;
    }
  }
  return smallest_elei;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}
void selection_sort(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    int smallest_elei = get_smallest_elei(arr, i, size);
    if (arr[i] > arr[smallest_elei]) {
      swap(arr[i], arr[smallest_elei]);
    }
  }
}
void print_arr(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << "arr[" << i << "]: " << arr[i] << '\n';
  }
}
int main() {
  constexpr int size = 4;
  int arr[size] = {1, 6, 7, 3};
  print_arr(arr, size);
  std::cout << "After sorting\n";
  selection_sort(arr, size);
  print_arr(arr, size);
}
