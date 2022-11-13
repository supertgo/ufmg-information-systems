#include<stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

void print_matrix(float m[][MAX_SIZE], int row_size, int col_size) {
  for(int i = 0; i < row_size; i++) {
    for(int j = 0; j < col_size; j++) {
      printf("%.2f ", m[i][j]);
    }
    printf("\n");
  }
}

float media_matriz(float m[][MAX_SIZE], int size) {
  float mean = 0;

  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      mean += m[i][j];
    }
  }

  return mean / size * size;
}

void identidade(float m[][MAX_SIZE], int size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
     if(i == j) {
      m[i][j] = 1;
     } else {
      m[i][j] = 0;
     }
    }
  }
}

void transposta(float A[][MAX_SIZE], float T[][MAX_SIZE], int size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      T[i][j] = A[j][i];
    }
  }
}

int simetrica(float A[][MAX_SIZE], int size) {
  float m_transposta[MAX_SIZE][MAX_SIZE];

  transposta(A, m_transposta, size);

  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
     if(m_transposta[i][j] != A[i][j]) {
        return 0;
     }
    }
  }

  return 1;
}


void soma_matriz(float A[][MAX_SIZE], float B[][MAX_SIZE], float S[][MAX_SIZE], int size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
     S[i][j] = B[i][j] + A[i][j];
    }
  }
}

void mult_matriz(float A[][MAX_SIZE], float B[][MAX_SIZE], float P[][MAX_SIZE], int size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      P[i][j] = 0;
      for (int k = 0; k < size; k++) {
        P[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

int main () {
  printf("Nome: Thiago Roberto Magalhães\n");
  printf("Matrícula: 2022066051\n");

  FILE *f = fopen("matriz.txt", "r");

  if(f ==NULL) {
    printf("Error: File not found.");
    return(1);
  }

  int rows, cols;
  float matrix[MAX_SIZE][MAX_SIZE], m_transposta[MAX_SIZE][MAX_SIZE], m_product[MAX_SIZE][MAX_SIZE];


  fscanf(f, "%d", &rows);
  fscanf(f, "%d", &cols);

  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
        fscanf(f, "%f", &matrix[i][j]);
    }
  }


  printf("\nMatriz lida a partir do arquivo:\n\n");
  print_matrix(matrix, rows, cols);

  printf("\nmedia da matriz é: %f\n\n", media_matriz(matrix, rows));
  transposta(matrix, m_transposta, rows);

  mult_matriz(matrix, m_transposta, m_product, rows);
  identidade(matrix, rows);
  printf("\nMatriz identidade:\n\n");

  print_matrix(matrix, rows, cols);

  printf("\nTransposta da Matriz :\n\n");
  print_matrix(m_transposta, rows, cols);

  printf("\n Multiplicacao da Matriz :\n\n");
  print_matrix(m_product, rows, cols);

	return 0;
}