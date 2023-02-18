#include <iostream>

int get_max(int *arr, int n) {
  int max = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

void print_array(int *arr, int n) {
  std::cout << "Array: ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}

int *counting_sort(int *arr, int n) {
  int k = get_max(arr, n) + 1;
  int *aux = new int[k]();
  int *sorted_arr = new int[n];
  for (int i = 0; i < n; ++i) {
    ++aux[arr[i]];
  }
  for (int i = 1; i < k; ++i) {
    aux[i] += aux[i - 1];
  }
  for (int i = n - 1; i >= 0; --i) {
    sorted_arr[aux[arr[i]] - 1] = arr[i];
    --aux[arr[i]];
  }
  return sorted_arr;
}

int main() {
  constexpr int SIZE = 4;
  int arr[SIZE] = {7, 1, 0, 8};
  std::cout << "Before sorting:-\n";
  print_array(arr, SIZE);
  int *sorted_arr = counting_sort(arr, SIZE);
  std::cout << "After sorting:-\n";
  print_array(sorted_arr, SIZE);
  return 0;
}
