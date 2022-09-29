#include<stdio.h>

int fat(int n) {
  if(n <= 1) {
    return 1;
  }

  return  n * fat(n - 1);
}

void swap(int x, int y) {
  int temp = x;
  x = y;
  y = temp;
}


int mdc(int a, int b) {

  if(a % b == 0) {
    return b;
  } 
    
  return mdc(b, a % b);  
}

int mdc3(int a, int b, int c) {
  if (a < c) {
    swap(a, c);
  }

  if (a < b) {
    swap(a, b);
  }

  if (b < c) {
    swap(b, c);
  }

  return mdc(mdc(a, b), c);
}

int fib(int n) {
  if(n <= 1) {
    return 1;
  }

  return fib(n - 1) + fib(n - 2);
}

int prime(int n, int i) {
  if (n <= 2) {
    return (n == 2) ? 1 : 0;
  } else if (n % i == 0) {
    return 1;
  } else if (i * i > n) {
    return 0;
  }

   return prime(n, i + 1);
}

void descending(int n) {
  if (n <= 1) {
    return;
  }

  printf("%d ", n - 1);
  
  return descending(n - 1);
}

int res(int a, int b) {
  if(a - b < 0) return a;

  return res(a - b, b);
}

int form (int n) {
   if(n <= 1) {
    return 1;
  }
  return(n * n + form(n - 1));
}

int mmc_aux(int a, int b, int aux) {
  if((a % b)) {
    return a;
  }

  return mmc_aux(a + aux, b, aux);
}

int mmc (int a, int b) {
  return mmc_aux(a, b, a);
}

int div (int a, int b) {
  return a / b;
}

float my_sqrt(float n, float guess) {

  float max = n + .001;
  float min = n - .001;
  float powerGuess = guess * guess;

  if(powerGuess > min && powerGuess < max) return guess;

  if(powerGuess < min) return my_sqrt(n, (guess * 1.05));

  if(powerGuess > max) return my_sqrt(n, (guess * 0.95));
}

int dig(int n) {
  if(n <= 9) {
    return n;
  }

  return n % 10  + dig(n / 10);
}

float my_exp(float k, float n) {
  if(n == 0) return 1;
  if(n == 1) return k;

  return k * my_exp(k, n - 1);
}

void crescent_aux(int current, int limit) {
  if(current > limit) {
    return;
  }

  printf("%d ", current);

  return crescent_aux(current + 1, limit);
}

void crescent(int limit) {
  return crescent_aux(1, limit);
}

int main () {

  printf("Nome: Thiago Roberto Magalhães\n");
  printf("Matrícula: 2022066051\n");
  
  printf("a) fat(n): retorna o valor do fatorial de 5: %d\n", fat(5));
  printf("b) mdc(a,b): retorna o máximo divisor comum entre 24 e 9: %d\n", mdc(24,9));
  printf("c) mdc3(a,b,c): retorna o máximo divisor comum entre 24, 9 e 5: %d\n", mdc3(24, 9, 5));
  printf("d) fib(n): retorna o quinto termo da série de Fibonacci, que é: %d\n", fib(5));
  printf("e) primo(x): predicado que testa se um número 13 é primo: %d\n", prime(13, 13));
  printf("f) decrescente(x): procedimento que escreve uma seqüência de inteiros menores que 20 e maiores que 0:\n");

  descending(10);

  printf("\ng) res(a,b): retorna o resto da divisão entre 13 e 5, que é : %d\n", res(13, 5));
  printf("h) form(n): retorna o valor do somatório de i*i, com i variando de 1 até 5, que é : %d\n", form(5));
  printf("i) mmc(a, b): retorna o menor múltiplo comum de 13 e 5, que é : %d\n", mmc(13, 5));
  printf("j) div(a, b): retorna o resultado da divisão inteira de 23 por 5, que é: %d\n", div(23, 5));
  printf("l) sqrt(n): retorna a raiz quadrada de 2 (com precisão de 0.001), que é: %.3f\n", my_sqrt(2, 2/1));
  printf("m) dig(n): retorna a soma dos dígitos de um inteiro positivo 132, que é : %d\n", dig(132));
  printf("n) exp(k, n): retorna 2 ^ 3, que é : %.2f\n", my_exp(2, 3));
  printf("o) crescente(x): escreve em ordem crescente, todos os inteiros maiores que 0 e menores ou iguais a 10.\n");

  crescent(10);

  printf("\n");

	return 0;
}