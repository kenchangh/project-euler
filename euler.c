#include <stdio.h>
#include <stdlib.h>

#define LENGTH(x) (sizeof x / sizeof x[0])


int *fib (int n) {
  int number;
  int* numbers = malloc(sizeof(int) *n);

  numbers[0] = 0;
  numbers[1] = 1;

  int i;
  int last2 = 0;
  int last = 1;

  for (i = 0; i < n; i++) {
    number = numbers[last] + numbers[last2];

    // Break on before the limit
    if (number >= n) {
      break;
    }

    numbers[last + 1] = number;
    last++;
    last2++;
  }

  // Exclude out starting point: 0, 1
  numbers = numbers + 2;
  return numbers;
}

int main() {
  int *fib_num;
  int size = 4000000;
  fib_num = fib(size);

  int fib_array[1000000];

  int i;
  int counter = 0;
  for (i = 0; i < size; i++) {
    if (fib_num[i] >= size || fib_num[i] == 0) {
      break; 
    }
    else {
      fib_array[counter] = fib_num[i];
      counter++;
    }
  }

  int even_sum = 0;
  for (i = 0; i < counter; i++) {
    int fib_num = fib_array[i];

    if (fib_num % 2 == 0) {
      even_sum += fib_num; 
    }
  }
  printf("%d", even_sum);

  return 0;
}

