#include <iostream>

using namespace std;

int main(){

    // 1) Declare uma variável do tipo inteiro e atribua o valor '10'
    int var = 10;

    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo (aka 'nullptr')
    int* p1 = nullptr;

    // 3) Declare um vetor de inteiros e inicialize com valores de 9 a 0 (nessa ordem)
    int vector[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << &var << endl;

    // 5) Imprima o CONTEÚDO da variável declarada em (1)
    cout << var << endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << &p1 << endl;

    // 7) Imprima o CONTEÚDO da variável declarada em (2)
    cout << p1 << endl;

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    cout << &vector << endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << &vector[0] << endl;

    // 10) Imprima o CONTEÚDO da primeira posição da variável declarada em (3)
    cout << vector[0] << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    p1 = &var;

    // 12) Imprima o CONTEÚDO da variável declarada em (2)
    cout << *p1 << endl;

    // 13) Imprima o CONTEÚDO da varíavel que é apontada por (2)
    cout << *p1 << endl;

    // 14) Imprima o resultado da comparação do ENDEREÇO de (1) e do CONTEÚDO de (2)
    cout << (&var == p1) << endl;

    // 15) Coloque o VALOR '5' na varíavel que é apontada pela variável de (2)
    var = 5;

    // 16) Imprima o CONTEÚDO da variável declarada em (1)
    cout << var << endl;

    // 17) Atribua o CONTEÚDO da variável de (3) à variável de (2)
    *p1 = vector[0];

    // 18) Imprima o CONTEÚDO da variável declarada em (2) 
    cout << *p1 << endl;

    // 19) Imprima o CONTEÚDO da variável que é apontada pela variável de (2)
    cout << var << endl;

    // 20) Atribua o ENDEREÇO da primeira posição de (3) à variável de (2)
    p1 = &vector[0];

    // 21) Imprima o CONTEÚDO da variável declarada em (2) 
    cout << *p1 << endl;

    // 22) Imprima o CONTEÚDO da variável que é apontada pela variável de (2) 
    cout << vector[0] << endl;

    // 23) Imprima os elementos de (3) utilizando a notação [] (e.g. v[i])
    for (int i = 0; i < 10; i++) {
      cout << vector[i] << " ";
      if (i == 9) {
        cout << vector[i] << endl;
      }
    }

    // 24) Imprima os elementos de (3) utilizando a notação ponteiro/deslocamento (e.g. *(v + i))
    for (int i = 0; i < 10; i++) {
      cout << *(vector + 1) << " ";    
      if (i == 9) {
        cout << *(vector + 1) << endl;    
      }
    }

    return 0;
}
