#include<stdio.h>

int fat(int n) {
  int sum = 1;

  while(n > 0) {
    sum *= n;
    n--;
  }

  return sum;
}

int mdc(int a, int b) {
  int rest = a % b;

  while(rest != 0) {
    a = b;
    b = rest;

    rest = a % b;
  }

  return b;
}

int max (int a, int b) {
  if(a > b) return a;

  return b;
}

int mdc3(int a, int b, int c) {   
  int maxi = 0;

  maxi = max(a, max(b, c));

  for(int i = maxi; i > 1; i--) {
    if(( a % i == 0 ) && ( b %i == 0 ) && ( c % i == 0 ))
      {
          return i;
          break;
      }
  }

 return 1;
}

int fib(int n) {
  int t1 = 0;
  int t2 = 1;
  int next = t1 + t2;

  for(int i = 3; i < n; i++) {
    t1 = t2;
    t2 = next;
    next = t1 + t2;
  }

  return next;
}

int prime(int n, int i) {
  if (n <= 2) {
    return (n == 2) ? 1 : 0;
  } 

  for(i == 0; ; i++) {
    if(n % i == 0) {
      return 1;
    }

    if(i * i > n) {
      return 0;
    }
  }
 
  return 0;
}

void descending(int n) {
  for (int i = n - 1; i > 1; i--) {
    printf("%d ", i);
  }

}

int res(int a, int b) {
  while(a != 0) {
    if(a - b < 0) return a;

    a = a - b;
  }

}

int form (int n) {
  int sum = 0;
  for(int i = 1; i <= n; i++) {
    if(n <= 1) {
      return 1;
    }

    sum += i * i;
  }

  return sum;
}


int mmc (int a, int b) {
  int aux = a;

  do {
    if(a % b) {
      return a;
    }

    a = a + aux;
  }
  while(a % b != 0);
}

int div (int a, int b) {
  return a / b;
}

float my_sqrt(float n, float guess) {

  float max = n + .001;
  float min = n - .001;
  float powerGuess = guess * guess;

  while(powerGuess < min || powerGuess > max) {
    if(powerGuess < min) {
      guess = guess * 1.05;
    } else {
      guess = guess * 0.95;
    }

    powerGuess = guess * guess;
  }

  return guess;
}

int dig(int n) {
  int sum = 0;

  while(n) {
    sum += n % 10;
    n = n / 10;
  }

  return sum;
}

float my_exp(float k, float n) {
  int result = 1;
  for (int i = 0; i < n; i++) {
    result *= k;
  }
  
  return result;
}


void crescent(int limit) {
  for(int i = 1; i < limit; i++) {
    printf("%d ", i);
  }
}

int main () {

  printf("Nome: Thiago Roberto Magalhães\n");
  printf("Matrícula: 2022066051\n");
  
  printf("a) fat(n): retorna o valor do fatorial de 5: %d\n", fat(5));
  printf("b) mdc(a,b): retorna o máximo divisor comum entre 24 e 9: %d\n", mdc(24,9));
  printf("c) mdc3(a,b,c): retorna o máximo divisor comum entre 24, 9 e 5: %d\n", mdc3(24, 9, 5));
  printf("d) fib(n): retorna o quinto termo da série de Fibonacci, que é: %d\n", fib(5));
  printf("e) primo(x): predicado que testa se um número 13 é primo: %d\n", prime(13, 13));
  printf("f) decrescente(x): procedimento que escreve uma seqüência de inteiros menores que 10 e maiores que 0:\n");

  descending(10);

  printf("\ng) res(a,b): retorna o resto da divisão entre 13 e 5, que é : %d\n", res(13, 5));
  printf("h) form(n): retorna o valor do somatório de i*i, com i variando de 1 até 5, que é : %d\n", form(5));
  printf("i) mmc(a, b): retorna o menor múltiplo comum de 13 e 5, que é : %d\n", mmc(13, 5));
  printf("j) div(a, b): retorna o resultado da divisão inteira de 23 por 5, que é: %d\n", div(23, 5));
  printf("l) sqrt(n): retorna a raiz quadrada de 2 (com precisão de 0.001), que é: %.3f\n", my_sqrt(2, 1));
  printf("m) dig(n): retorna a soma dos dígitos de um inteiro positivo 132, que é : %d\n", dig(132));
  printf("n) exp(k, n): retorna 2 ^ 3, que é : %.2f\n", my_exp(2, 3));
  printf("o) crescente(x): escreve em ordem crescente, todos os inteiros maiores que 0 e menores ou iguais a 10.\n");

  crescent(10);

  printf("\n");

	return 0;
}