#include<stdio.h>

float max(float a, float b, float c) {
  float greater = a;

  if(b >= greater) {
    greater = b;
  }

  if(c >= greater) {
    greater = c;
  }

  return greater;
}

float min(float a, float b, float c) {
  float greater = a;

  if(b <= greater) {
    greater = b;
  }

  if(c <= greater) {
    greater = c;
  }

  return greater;
}

int isDivisible(int number, int divisor) {
  return number % divisor == 0 ? 1 : 0; 
}

int par(int number) {
  return isDivisible(number, 2);
}

int dentro(float x, float y, float z) {
  float smallest, greater;
  if(y >= z) {
    greater = y;
    smallest = z;
  } else {
    greater = z;
    smallest = y;
  };

  return (smallest <= x && x <= greater) ? 1 : 0;
}

int fora (float x, float y, float z) {
  return !dentro(x, y, z);
}



int bissexto(int year) {
  if(isDivisible(year, 400) || 
    (isDivisible(year, 4) && !isDivisible(year, 100))
    ) {
    return 1;
  } 

  return 0;
}


int main () {
  float x, y, z;

  printf("Nome: Thiago Roberto Magalhães\n");
  printf("Matrícula: 2022066051\n");

  printf("Escreva o valor de x: ");
  scanf("%f", &x);

  printf("\nEscreva o valor de y: ");
  scanf("%f", &y);

  printf("\nEscreva o valor de z: ");
  scanf("%f", &z);

  printf("1. Escreva as seguintes funções em C++:\n");

  printf("a) max(x,y,z): Retorna o maior dentre três números: %.2f\n", max(x, y, z));
  printf("b) min(x,y,z): Retorna o menor dentre três números: %.2f\n", min(x, y, z));

  printf("2. Escreva os seguintes predicados em C++:\n");

  printf("a) par(x): Retorna 1 se o número é par e 0 caso contrário: %d\n", par(x));
  printf("b) dentro(x,y,z): testa se o número x está dentro do intervalo [y z], retorna 1 se está dentro e 0 caso contrário: %d\n", dentro(x, y, z));
  printf("c) fora(x,y,z): testa se o número x está fora do intervalo [y z] retorna 1 se está fora 0 caso contrário: %d\n", fora(x, y, z));

  printf(
    "3. Defina o predicado bissexto(ano) que testa se um ano é bissexto. Considere que"
    "bissexto é aquele ano que é divisível por 400 ou é divisível por 4 e, nesse caso, não é"
    "divisível por 100.:\n"
  );

  printf("Obs: A função retornará 1 caso o ano for bissexto ou 0 caso contrário\n");

  printf("O ano 2000 é: %d\n", bissexto(2000));
  printf("O ano 1900 é: %d\n", bissexto(1900));
  printf("O ano 3600 é: %d\n", bissexto(3600));
  printf("O ano 2004 é: %d\n", bissexto(2004));

	return 0;
}