#include <math.h>
#include <stdio.h>
#include <string.h>
int count_digits(int key) {
  int count = 0;
  while (key != 0) {
    key /= 10;
    ++count;
  }
  return count;
}
int fold_shift(int key, int size) {
  int key_roll = key;
  int key_sum = 0;
  int key_frac = 0;
  int key_length = 0;
  int fraction = size;
  key_length = count_digits(key_roll);
  while (key_length > 0) {
    if (key_length > fraction) {
      key_frac = key_roll / (int)pow(10, (key_length - fraction));
      key_sum += key_frac;
      key_roll = key_roll % (int)pow(10, (key_length - fraction));
      key_length = key_length - fraction;
    } else {
      key_sum += key_roll;
      break;
    }
  }
  return key_sum % (int)pow(10, (fraction));
}
int main() {
  printf("\n\n%d", fold_shift(12789, 3));    // 216
  printf("\n\n%d", fold_shift(12345678, 1)); // 6
  printf("\n\n%d", fold_shift(5678, 2));     // 34
  return 0;
}
