#include "../c_header/sort.h"

int int_cmp(const void *a, const void *b) {
  return (*(int *)a < *(int *)b) ? -1 : (*(int *)a == *(int *)b ? 0 : 1);
}

void hello() { printf("Hello from C!\n"); }

void print_array(int *array, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}