#include <stdio.h>

void digit_extraction(int key) {
  int key_length = 0;
  int first_digit = 0;
  int fourth_digit = 0;
  first_digit = key % 10000000;
  first_digit = first_digit / 1000000;
  fourth_digit = key % 1000;
  fourth_digit = fourth_digit / 100;
  printf("%d key would be hashed at location %d%d\n", key, first_digit,
         fourth_digit);
}
int main() {
  digit_extraction(1347878);
  digit_extraction(1234678);
  return 0;
}
