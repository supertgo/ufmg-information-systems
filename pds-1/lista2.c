#include<stdio.h>
#include<math.h>
#define PI 3.14

float media (float a, float b, float c) {
	return (a + b + c) / 3;
}

float mediaPonderada (float a, float b, float c) {
	return (3 * a + 4 * b + 5 * c) / (3 + 4 + 5); 
}

float perimetroCirculo (float r) {
	return (2 * PI * r);
}

float areaCirculo (float r) {
	return (PI * pow(r, 2));
}

float areaTriangulo (float b, float c) {
	return (b * c / 2);
}

float areaCaixa (float a) {
	return (6 * a * a);
}


float volumeCaixa (float a, float b, float c) {
	return (a * b * c);
}

float areaCilindro (float r, float h) {
	return (2 * areaCirculo(r) + ( h * perimetroCirculo(r)));
}

float volumeCilindro (float r, float h) {
	return areaCirculo(r) * h;
}

float hipotenusa (float b, float c) {
	return (sqrt(pow(b, 2) + pow(c, 2)));
}


float calculaDelta(float a, float b, float c) {
	return (pow(b, 2) - 4 * a * c);
}

float calculaRaiz(float a, float b, float c, float delta) {
  return (((b * -1) + sqrt(delta)) / (2 * a));
}


float raizPositiva(float a, float b, float c) {
	float x, x2;
	float delta = calculaDelta(a, b, c);
	
	return calculaRaiz(a, b, c, delta);
}


int main () {
  float a, b, c;
   printf("Nome: Thiago Roberto Magalhães\n");
  printf("Matrícula: 2022066051\n");

  printf("Escreva o valor de a: ");
  scanf("%f", &a);

  printf("\nEscreva o valor de b: ");
  scanf("%f", &b);

  printf("\nEscreva o valor de c: ");
  scanf("%f", &c);


	printf("a) Média: %.2f\n", media(a, b, c));
  printf("b) Média ponderada: %.2f\n", mediaPonderada(a, b, c));
  printf("c) Perímetro de um circulo de raio a: %.2f\n", perimetroCirculo(a));
  printf("d) Área do círculo de um circulo de raio a: %.2f\n", areaCirculo(a));
  printf("e) Área do triângulo de base b e altura c: %.2f\n", areaTriangulo(b, c));
  printf("f) Área da caixa considerando que a caixa é um cubo de lado a: %.2f\n", areaCaixa(a));
  printf("g) Volume da caixa: %.2f\n", volumeCaixa(a, b, c));
  printf("h) Área do cilindro, calcula a área de um cilindro de raio r e altura h: %.2f\n", areaCilindro(a, b));
  printf("i) Área do cilindro, calcula a área de um cilindro de raio r e altura h: %.2f\n", volumeCilindro(a, b));
  printf("j) Hipotenusa, calcula a hipotenusa de um triângulo retângulo com lados b e c. : %.2f\n", hipotenusa(b, c));
  printf("k) Raiz positiva, você devera ler os valores de x2 e x: %.2f\n", raizPositiva(a, b, c));
	return 0;
}