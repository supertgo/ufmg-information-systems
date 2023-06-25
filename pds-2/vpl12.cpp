#include "vetor.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  try {
    int inicio, fim;
    cin >> inicio >> fim;
    Vetor v(inicio, fim);
    char opcao;
    while (cin >> opcao) {
      int indice;
      string valor;
      if (opcao == 'a') {
        cin >> indice;
        cin >> valor;
        try {
          v.atribuir(indice, valor);
        } catch (IndiceInvalido e) {
          cout << "Não foi possível executar a operação: índice " << e.indice
               << " não pertence ao intervalo [" << e.inicio << ", " << e.fim
               << "]." << endl;
          exit(1);
        }
      } else if (opcao == 'v') {
        cin >> indice;
        try {
          v.valor(indice);
        } catch (IndiceNaoInicializado e) {
          cout << "Não foi possível executar a operação: índice " << e.indice
               << " não foi inicializado." << endl;
          exit(1);
        } catch (IndiceInvalido e) {
          cout << "Não foi possível executar a operação: índice " << e.indice
               << " não pertence ao intervalo [" << e.inicio << ", " << e.fim
               << "]." << endl;
          exit(1);
        }

        valor = v.valor(indice);
        cout << valor << endl;
      } else if (opcao == 'f') {
        return 0;
      } else {
        cout << "Opção inválida!" << endl;
      }
    }
  } catch (IntervaloVazio e) {
    cout << "Não foi possível executar a operação: intervalo [" << e.inicio
         << ", " << e.fim << "] é vazio." << endl;
  }
  return 0;
}
