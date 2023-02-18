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

void copy_array(int *src, int *dest, int n) {
  for (int i = 0; i < n; ++i) {
    dest[i] = src[i];
  }
}

void print_array(int *arr, int n) {
  std::cout << "Array: ";
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}

int digit_at(int num, int place) { return (num / place) % 10; }

void counting_sort(int *arr, int place, int n) {
  constexpr int NUM_OF_DIGITS = 10;
  int *aux = new int[NUM_OF_DIGITS]();
  int *sorted_arr = new int[n];
  for (int i = 0; i < n; ++i) {
    ++aux[digit_at(arr[i], place)];
  }
  for (int i = 1; i < NUM_OF_DIGITS; ++i) {
    aux[i] += aux[i - 1];
  }
  for (int i = n - 1; i >= 0; --i) {
    sorted_arr[aux[digit_at(arr[i], place)] - 1] = arr[i];
    --aux[digit_at(arr[i], place)];
  }
  copy_array(sorted_arr, arr, n);
}

void radix_sort(int *arr, int n) {
  int max = get_max(arr, n);
  for (int place = 1; max / place > 0; place *= 10) {
    counting_sort(arr, place, n);
  }
}

int main() {
  constexpr int SIZE = 4;
  int arr[SIZE] = {3, 1729, 891, 890};
  std::cout << "Before sorting:-\n";
  print_array(arr, SIZE);
  radix_sort(arr, SIZE);
  std::cout << "After sorting:-\n";
  print_array(arr, SIZE);
  return 0;
}
