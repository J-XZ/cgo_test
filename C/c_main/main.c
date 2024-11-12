#include "../c_header/sort.h"

int main() {
  printf("this is c test\n");
  hello();

  int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  printf("Before sorting: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  
  qsort(array, 10, sizeof(int), int_cmp);

  printf("After sorting: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
