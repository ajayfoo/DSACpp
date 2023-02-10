#include <iostream>

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}
void bubble_sort(int arr[], int size) {
  for (int pass{0}; pass < size - 1; ++pass) {
    for (int j{0}; j < size - pass - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

void print_arr(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << "arr[" << i << "]: " << arr[i] << '\n';
  }
}
int main() {
  constexpr int size = 5;
  int arr[size] = {1, 6, 7, 3, 2};
  print_arr(arr, size);
  std::cout << "After sorting\n";
  bubble_sort(arr, size);
  print_arr(arr, size);
}
