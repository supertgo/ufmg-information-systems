#include<stdio.h>
#include <stdlib.h>

int prime(int n) {
  if(n <= 2) return (n == 2) ? 1 : 0;
  if(n % 2 == 0) return 0;

  for(int i = 2; ;i++) {
    if(n % i == 0) {
      return 0;
    }

    if(i * i > n) {
      return 1;
    }
  }
 
  return 0;
}

void write_primes(int limit, FILE *file) {
  if(limit <= 0) return;

  int current = 2;
  int count = 1;

  while(count <= limit) {
    if(prime(current) == 1) {
      fprintf(file, "%d ", current);
      count++;
    }
    current++;
  }

  return;
}

float expression_four(float x) {
  return  x * x -5 * x + 1;
}

float expression_five(float a, float b, float c, float d, float x) {
  return a * x * x * x + b * x * x + c * x + d; 
}

int main () {
  printf("Nome: Thiago Roberto Magalhães\n");
  printf("Matrícula: 2022066051\n");

  int limit;
  FILE *fptr, *ptr,* quest2Answers,* primos,* outros, *reais, *resultReais, *result5;

  int i = 0;

   if((fptr = fopen("lista6.txt", "w+")) == NULL) {
     printf("Error! opening file");
     exit(1);
   }

   printf("Leia o número de primos que você deseja que tenha no arquivo\n");
   scanf("%d", &limit);


  write_primes(limit, fptr);

  fclose(fptr);

  ptr = fopen("lista6quest2.txt", "r");
  quest2Answers = fopen("lista6quest2answers.txt", "w+");
  primos = fopen("primos.txt", "w+");
  outros = fopen("outros.txt", "w+");
  reais = fopen("reais.txt", "r");
  resultReais = fopen("resultado-reais.txt", "w+");
  result5 = fopen("result5.txt", "w+");

  if (NULL == reais) {
      printf("file can't be opened \n");
  }
  

  if (NULL == ptr) {
      printf("file can't be opened \n");
  }

  if(NULL == quest2Answers) {
      printf("file can't be opened \n");
  }

  if (NULL == primos) {
      printf("file can't be opened \n");
  }

  if (NULL ==outros) {
      printf("file can't be opened \n");
  }

  do {
    fscanf (ptr, "%d", &i);    
    printf ("%d ", i);
    if(prime(i) == 1) {
      fprintf(quest2Answers, "%s", "eh primo\n");
      fprintf(primos, "%d", i);
      fprintf(primos, "%s", "\n");
    } else {
      fprintf(quest2Answers, "%s", "n eh primo\n");
      fprintf(outros, "%d", i);
      fprintf(outros, "%s", "\n");
    }
  }while (!feof (ptr));
  fclose(ptr);

  float a, b, c, d, x;
  
  printf("\nLeia os 4 numeros");

  scanf("%f%f%f%f", &a, &b, &c, &d);

  do {
    fscanf (reais, "%f", &x);    
    fprintf(resultReais, "%f\n", expression_four(x));
    fprintf(result5, "%f\n", expression_five(a, b, c, d, x));
  }while (!feof (reais));
 

	return 0;
}