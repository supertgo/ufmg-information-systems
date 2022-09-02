#include <stdio.h>
#include <math.h>
#define PI 3.14

int main () {
  printf("Nome: Thiago Roberto Magalhães\n");
  printf("Matrícula: 2022066051\n");

  printf("1. Escreva um programa em C++ que resolva as seguintes expressões:\n");
  printf("a) %d\n", 3 + 4);
  printf("b) %.2f\n", 7.0 / 4.0);
  printf("c) %.2f\n", pow(3,2));
  printf("d) %.2f\n", 5.3 * 2.1);
  printf("e) %d\n", 2 * 5 - 2);
  printf("f) %d\n", 2 + 2 * 5);
  printf("g) %d\n", (2 + 5) * 3);
  printf("h) %.6f\n", sin(3.141502));
  printf("i) %.2f\n", sqrt(5));
  printf("j) %d\n", 1 + 2 + 3);
  printf("k) %d\n", 1 * 2 * 3);
  printf("l) %.2f\n", (1 + 2 + 3) / 3.0);
  printf("m) %d\n", (2 + 4) * ( 3 - 1));
  printf("n) %d\n", (9 / 3) + (3 * 2));
  printf("o) %.2f\n", sin(4.5) + cos(3.7));
  printf("p) %2.f\n", log(2.3) - log(3.1));
  printf("q) %2.f\n", log (7) + (log(7) * log(7) - cos(log(7))));
  printf("r) %2.f\n", (10.3 + 8.4)/50.3 - (10.3 + 8.4));
  printf("s) %2.f\n", cos(0.8) + sin(0.8)) * (cos(0.8) - sin(0.8));

  printf("2. Escreva um programa em C++ que lê quatro números reais do teclado" 
    "(a, b, c e d) e exibe o resultado das seguintes expressões:\n");

  float a;
  float b;
  float c;
  float d;

  printf("Escreva o valor de a: ");
  scanf("%f", &a);

  printf("\nEscreva o valor de b: ");
  scanf("%f", &b);

  printf("\nEscreva o valor de c: ");
  scanf("%f", &c);

  printf("\nEscreva o valor de d: ");
  scanf("%f", &d);

  printf("a) a + b: %.2f\n", a + b);
  printf("b) a / c: %.2f\n", a / c );
  printf("c) a^2: %.2f\n", pow(a, 2));
  printf("d) b * c: %.2f\n", b * c);
  printf("e) a * b - c: %.2f\n", a * b - c);
  printf("f) a + b * c: %.2f\n", a + b * c);
  printf("g) (a + b) * c: %.2f\n", (a + b) * c);
  printf("h) sin(a): %.2f\n", sin(a));
  printf("i) sqrt(b): %.2f\n", sqrt(b));
  printf("j) a + b + c: %.2f\n", a + b + c);
  printf("k) a * b * c: %.2f\n", a * b * c);
  printf("l) (a + b + c) / d: %.2f\n", (a + b + c) / d);
  printf("m) (a + b) * (a - d): %.2f\n", (a + b) * (a - d));
  printf("n) (b / c) + (a * d): %.2f\n", (b / c) + (a * d));
  printf("o) sin(b) + cos(c): %.2f\n", sin(b) + cos(c));
  printf("p) log(a) - log c: %.2f\n", log(a) - log(c));

  printf("3. Escreva um programa em C++ que lê três números reais do teclado"
   "(a, b e c) e exibe o resultado das seguintes expressões:\n");
  
  printf("Escreva o valor de a: ");
  scanf("%f", &a);

  printf("\nEscreva o valor de b: ");
  scanf("%f", &b);

  printf("\nEscreva o valor de c: ");
  scanf("%f", &c);

  float delta = pow(b, 2)  - 4 * a * c;
  float root1 = (-1 * b  + delta)/ 2 * a;
  float root2 = (-1 * b  + -1 * delta)/ 2 * a;

  printf("a) Média: %.2f\n", (a + b + c) / 3);
  printf("b) Média ponderada: %.2f\n", (a * 3 + b * 4 + c * 5)/ (3 + 4 + 5));
  printf("c) Perímetro: %.2f\n", 2 * PI * a);
  printf("d) Área do círculo: %.2f\n", PI * pow(a, 2));
  printf("e) Área do triangulo: %.2f\n", b * c / 2);
  printf("f) Hipotenusa: %.2f\n", sqrt(pow(b, 2) + pow(c, 2)));
  printf("g) Raízes: primeira raiz tem o valor %.2f, segunda raiz tem  o valor %.2f\n", root1, root2);

  return 0;
}