#include <iostream>

#include "dicionario.h"

using namespace std;

int main() {
  Dicionario m;
  string operacao, chave, valor;
  while (cin >> operacao) {
    try {
      if (operacao == "m") {
        try {
          cout << m.menor() << endl;

        } catch (DicionarioVazio e) {
          cout << "Não foi possível realizar a operação: Dicionário vazio"
               << endl;
        }
      } else if (operacao == "t") {
        cout << m.tamanho() << endl;
      } else if (operacao == "p") {
        cin >> chave;
        if (m.pertence(chave)) {
          cout << "sim" << endl;
        } else {
          cout << "não" << endl;
        }
      } else if (operacao == "v") {
        cin >> chave;
        try {
          cout << m.valor(chave) << endl;
        } catch (ChaveInexistente e) {
          cout << "Não foi possível realizar a operação: A chave " << e.chave
               << " não está no dicionário" << endl;
        }
      } else if (operacao == "i") {
        cin >> chave >> valor;
        try {
          m.Inserir(chave, valor);
        } catch (ChaveRepetida e) {
          cout << "Não foi possível realizar a operação: A chave " << e.chave
               << " já está no dicionário" << endl;
        }
      } else if (operacao == "r") {
        cin >> chave;
        try {
          m.Remover(chave);
        } catch (ChaveInexistente e) {
          cout << "Não foi possível realizar a operação: A chave " << e.chave
               << " não está no dicionário" << endl;
        }
      } else if (operacao == "a") {
        cin >> chave >> valor;
        try {
          m.Alterar(chave, valor);
        } catch (ChaveInexistente e) {
          cout << "Não foi possível realizar a operação: A chave " << e.chave
               << " não está no dicionário" << endl;
        }
      } else {
        return 0;
      }
    } catch (DicionarioVazio e) {
      cout << "Não foi possível realizar a operação: Dicionário vazio" << endl;
    }
  }
}
