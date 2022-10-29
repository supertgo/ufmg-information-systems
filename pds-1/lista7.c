#include<stdio.h>
#include <stdlib.h>

float mean(float v[], int size) {
  float sum = 0;
  for(int i = 0; i < size; i++) {
    sum+= v[i];
  }

  return sum / size;
}

float variance(float v[], int size) {
  float sum = 0, aux;
  float v_mean = mean(v, size);

  for (int i = 0; i < size; i++) {
    aux = v[i] - v_mean;
    sum += aux * aux;
  }

  return sum/(size - 1);
}

float greater(float v[], int size) {
  float greater = v[0];

  for (int i = 0; i < size; i++) {
    if(v[i] > greater) {
      greater = v[i];
    }
  }

  return greater;
}

float smallest(float v[], int size) {
  float smallest = v[0];

  for (int i = 0; i < size; i++) {
    if(v[i] < smallest) {
      smallest = v[i];
    }
  }

  return smallest;
}

float dot_product(float v[], float u[], int size) {
  float product = 0;

  for (int i = 0; i < size; i++) {
    product += v[i] * u[i];
  }

  return product;
}

int main () {
  printf("Nome: Thiago Roberto Magalhães\n");
  printf("Matrícula: 2022066051\n");

  FILE *quest1;
  int index = 0, v1[10];
  float v2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  float u[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

  quest1 = fopen("lista7quest1.txt", "r");

  printf("Os valores em v1 listo dos arquivos eh: \n");
  do {
    fscanf (quest1, "%d", &v1[index]);    
    printf("%d ", v1[index]);
    index++;
  }while (!feof (quest1));
  printf("\n");


  printf("A media do vetor v2 de 10 elementos é: %f\n", mean(v2, 10));
  printf("A a variancia do vetor v2 de 10 elementos é: %f\n", variance(v2, 10));
  printf("O maior valor de v2 é: %f\n", greater(v2, 10));
  printf("O menor valor de v2 é: %f\n", smallest(v2, 10));
  printf("O produto escalar de v2 é: %f\n", dot_product(v2, u, 10));
  

	return 0;
}