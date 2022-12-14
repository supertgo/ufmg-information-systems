#include <stdio.h>
#include<stdio.h>
#include <math.h>
#define PI 3.14

typedef struct _Ponto {
  float x;
  float y;
} Ponto;

typedef struct _Triangle {
  Ponto a;
  Ponto b;
  Ponto c;
} Triangle;

typedef struct _Rectangle {
  Ponto a;
  Ponto b;
  Ponto c;
  Ponto d;
} Rectangle;

typedef struct _Circle {
  Ponto c;
  float radius;
} Circle;

float circle_perimeter(Circle c) {
  return 2 * PI * c.radius;
}

float circle_area(Circle c) {
  return PI * c.radius * c.radius;
}

void constructor(Ponto *p, float x, float y) {
  p->x = x;
  p->y = y;

  return;
}

float distance(Ponto p1, Ponto p2) {
  float x = p2.x - p1.x;
  float y = p2.y - p1.y;

  return sqrt(pow(x, 2) + pow(y, 2));
}

float perimeter (Triangle t) {
  float distanceAB = distance(t.a, t.b);
  float distanceAC = distance(t.a, t.c);
  float distanceCB = distance(t.c, t.b);

  return distanceAB + distanceAC + distanceCB;
}

float rectangle_perimeter (Rectangle r) {
  float distanceAB = distance(r.a, r.b);
  float distanceAC = distance(r.a, r.c);
  float distanceBD = distance(r.b, r.d);
  float distanceCD = distance(r.c, r.d);

  return distanceAB + distanceAC + distanceBD + distanceCD;
}


float cross_product_v_norm(Ponto p1, Ponto p2) {
   return p1.x * p2.y - p1.y * p2.x;
}


int is_quad(Rectangle r) {
  float distanceAB = distance(r.a, r.b);
  float distanceAC = distance(r.a, r.c);
  float distanceBD = distance(r.b, r.d);
  float distanceCD = distance(r.c, r.d);

  if(distanceAB == distanceAC && distanceAC == distanceBD && distanceBD == distanceCD) {
    return 1;
  }

  return 0;
}

Ponto diff(Ponto a, Ponto b) {
  float x = b.x - a.x;
  float y = b.y - a.y;
  Ponto p; 

  constructor(&p, x, y);

  return p;
}

float rectangle_area (Rectangle r) {
  Ponto v_ab = diff(r.a, r.b);
  Ponto v_ac = diff(r.a, r.c);

  return cross_product_v_norm(v_ab, v_ac);
}


float area (Triangle t) {
  Ponto v_ab = diff(t.a, t.b);
  Ponto v_bc = diff(t.b, t.c);

  return cross_product_v_norm(v_ab, v_bc) / 2;
}

int equilateral(Triangle t) {
  float distanceAB = distance(t.a, t.b);
  float distanceAC = distance(t.a, t.c);
  float distanceCB = distance(t.c, t.b);

  if(distanceAB == distanceAC && distanceAC == distanceCB) {
    return 1;
  }

  return 0;
}

int similar_triangle(Triangle t,  Triangle r) {
  if(pow(distance(t.a, t.b) / distance(r.a, r.b), 2) == area(t)/ area(r)) {
    return 1;
  }

  return 0;
}

int is_dot_in_circle(Circle c, Ponto p) {
  float d_pcircle = distance(c.c, p);

  if(d_pcircle <= c.radius) return 1;

  return 0;
}

int is_triangle_in_circle(Circle c, Triangle t) {
  if(is_dot_in_circle(c, t.a) && is_dot_in_circle(c, t.b) && is_dot_in_circle(c, t.c)) {
    return 1;
  }

  return 0;
}

int is_rectangle_in_circle(Circle c, Rectangle r) {
  if(is_dot_in_circle(c, r.a) 
      && is_dot_in_circle(c, r.b) 
      && is_dot_in_circle(c, r.c) 
      && is_dot_in_circle(c, r.d)
    ) {
    return 1;
  }

  return 0;
}

int dot_belongs_circumference(Circle c, Ponto p) {
   float d_pcircle = distance(c.c, p);

   return d_pcircle == c.radius ? 1 : 0;
}

int circumference_circunscrita_tri(Circle c, Triangle t){                                                   // Exerc??cio 20
    if(dot_belongs_circumference(c,t.a) 
        && dot_belongs_circumference(c,t.b) 
        && dot_belongs_circumference(c,t.c)
      ){
        return 1;
    }
    else{
        return 0;
    }
}


int circumference_circunstrita_ret(Circle c, Rectangle r){                                                   // Exerc??cio 21
    if(dot_belongs_circumference(c,r.a) 
        && dot_belongs_circumference(c,r.b) 
        && dot_belongs_circumference(c,r.c) 
        && dot_belongs_circumference(c,r.d)
      ){
        return 1;
    }
    else{
        return 0;
    }
}


int main () {
  Ponto p1, p2;
  constructor(&p1,1,2);
  constructor(&p2,3,4);
  printf("Ponto P1: %.2f, %.2f\n", p1.x, p1.y);
  printf("Ponto P2: %.2f, %.2f\n", p2.x, p2.y);
  printf("Distancia entre os pontos P1 e P2: %.2f\n",distance(p1, p2));

  Triangle t1={{1,2}, {4,2}, {4,6}}, t2={{3,4}, {6,4}, {6,8}};
  printf("\nPontos do Tri??ngulo 'T1': (%.2f, %.2f), (%.2f, %.2f), (%.2f, %.2f)\n", t1.a.x, t1.b.y, t1.b.x, t1.b.y, t1.c.x, t1.c.y);
  printf("Perimetro do triangulo T1: %.2f\n", perimeter(t1));
  printf("Area do triangulo T1: %.2f\n", area(t1));
  printf("Tri??ngulo T2: (%.2f, %.2f), (%.2f, %.2f), (%.2f, %.2f)\n", t2.a.x, t2.a.y, t2.b.x, t2.b.y, t2.c.x, t2.c.y);
  printf("Detalhes do triangulo T1:\n");

  if(equilateral(t1)){
      printf("Tri??ngulo equilatero\n");
  }
  else{
      printf("Tri??ngulo n??o equilatero\n");
  }

  printf("Os tri??ngulos T1 e T2 s??o:\n");
  if(similar_triangle(t1,t2)){
      printf("Tri??ngulos semelhantes\n");
  }
  else{
      printf("Tri??ngulos n??o semelhantes\n");
  }

  // Testes Parte III
    Rectangle r1={{1,2}, {5,2}, {5,5}, {1,5}};
    printf("\nPontos do Retangulo 'R1': (%.2f, %.2f), (%.2f, %.2f), (%.2f, %.2f), (%.2f, %.2f)\n", r1.a.x, r1.a.y, r1.b.x, r1.b.y, r1.c.x, r1.c.y, r1.d.x, r1.d.y);
    printf("Perimetro do retangulo R1: %.2f\n",rectangle_perimeter(r1));
    printf("Area do retangulo R1: %.2f\n",rectangle_area(r1));
    printf("O Retangulo R1 ??:\n");

    if(is_quad(r1)){
        printf("Quadrado\n");
    }
    else{
        printf("N??o quadrado\n");
    }

    // Testes Parte IV
    Circle c1={{1,1}, 4};
    printf("\nCentro da circunfer??ncia C1: (%.2f, %.2f)\n", c1.c.x, c1.c.y);
    printf("Raio da circunfer??ncia C1: %.2f\n", c1.radius);
    printf("Per??metro da circunfer??ncia C1: %.2f\n", circle_perimeter(c1));
    printf("Area da circunfer??ncia C1: %.2f\n", circle_area(c1));
    printf("O ponto P1 est?? contido na circunfer??ncia C1?\n");

    if(is_dot_in_circle(c1,p1)){
        printf("Sim\n");
    }
    else{
        printf("N??o\n");
    }
    printf("O triangulo T1 est?? contido na circunfer??ncia C1?\n");
    if(is_triangle_in_circle(c1,t1)){
        printf("Sim\n");
    }
    else{
        printf("N??o\n");
    }
    printf("O retangulo R1 est?? contido na circunfer??ncia C1?\n");
    if(is_rectangle_in_circle(c1,r1)){
        printf("Sim\n");
    }
    else{
        printf("N??o\n");
    }

    printf("O ponto P1 est?? na linha definida pela circunfer??ncia C1?\n");
    if(dot_belongs_circumference(c1,p1)){
        printf("Sim\n");
    }
    else{
        printf("N??o\n");
    }
    printf("O triangulo T1 ?? circunscrito a C1?\n");
    if(circumference_circunscrita_tri(c1,t1)){
        printf("Sim\n");
    }
    else{
        printf("N??o\n");
    }
    printf("O retangulo R1 ?? circunscrito a C1?\n");
    if(circumference_circunstrita_ret(c1,r1)){
        printf("Sim\n");
    }
    else{
        printf("N??o\n");
    }

    return 0;
}