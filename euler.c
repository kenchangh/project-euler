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


int sumOfEvenFib() {
    int *fibNum;
    int size = 4000000;
    fibNum = fib(size);

    int fibArray[1000000];

    int i;
    int counter = 0;
    for (i = 0; i < size; i++) {
        if (fibNum[i] >= size || fibNum[i] == 0) {
            break; 
        }
        else {
            fibArray[counter] = fibNum[i];
            counter++;
        }
    }

    int evenSum = 0;
    for (i = 0; i < counter; i++) {
        int fibNum = fibArray[i];

        if (fibNum % 2 == 0) {
            evenSum += fibNum; 
        }
    }

    return evenSum;
}


