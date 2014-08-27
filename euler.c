# include <stdio.h>
# include <stdlib.h>


int len(int array[4000000]) {
  return sizeof(array) / sizeof(int);
}


int *fib (int n) {
  int number;
  int* numbers = malloc(sizeof(int)*n);

  numbers[0] = 0;
  numbers[1] = 1;

  int i;
  int last2 = 0;
  int last = 1;

  for (i = 0; i < n; i++) {
    number = numbers[last] + numbers[last2];

    numbers[last + 1] = number;
    last++;
    last2++;
  }

  // Exclude out starting point: 0, 1
  numbers = numbers + 2;
  return numbers;
}


int *filter_even(int *array, int size) {
  int* numbers = malloc(sizeof(int)*(size/2));
}


int main() {
  int *fib_num;
  fib_num = fib(10);

  int i;
  printf("%d", len(fib_num));
  for (i = 0; i < 10; i++) {
    printf("%d\n", fib_num[i]);
  }
  return 0;
}










