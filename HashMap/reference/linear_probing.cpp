#include <stdio.h>
#define size 10
int ht[size];
void store(int x[], int n);
int modulodivision(int key);
int linearprobe(int address);
int main() {
  int i, n, x[10];
  char ch;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Enter the elements:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  store(x, n);
  printf("Hashtable is as shown:\n");
  for (i = 0; i < size; i++) {
    printf("%d ", ht[i]);
  }
}

void store(int x[], int n) {
  int i, key, address;
  /* Initializing hash table to empty */
  for (i = 0; i < size; i++)
    ht[i] = -1;
  /* Copying elements from original array to hashtable */
  for (i = 0; i < n; i++) {
    key = x[i];
    address = modulodivision(key);
    if (ht[address] != -1)
      address = linearprobe(address);
    ht[address] = key;
  }
}

int modulodivision(int key) {
  int address;
  address = key % size + 1;
  if (address == size) {
    return 0;
  } else {
    return address;
  }
}

int linearprobe(int address) {
  while (ht[address] != -1) {
    address++;
    if (address == size)
      address = 0;
  }
  return address;
}
