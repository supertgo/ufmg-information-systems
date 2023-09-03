#include "fib.h"
#include <iostream>
#include <math.h>
#include <stdio.h>

unsigned long long int fib_recursivo(unsigned long long int target) {
  return target < 2 ? target
                    : fib_recursivo(target - 1) + fib_recursivo(target - 2);
}

unsigned long long int fib_iterativo(unsigned long long int target) {
  if (target <= 1) {
    return target;
  }

  unsigned long long int previous = 0;
  unsigned long long int current = 1;

  for (unsigned long long int i = 2; i <= target; i++) {
    unsigned long long int next = previous + current;
    previous = current;
    current = next;
  }

  return current;
}

unsigned long long int fib_recursivo_sen(unsigned long long int target) {
  for (int i = 0; i <= 10000000; ++i) {
    sin(i);
  }

  return target < 2
             ? target
             : fib_recursivo_sen(target - 1) + fib_recursivo_sen(target - 2);
}
