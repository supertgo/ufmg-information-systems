#include <iostream>
#include "vetor.h"
#include <string>

Vetor::Vetor(int inicio, int fim){
  if (inicio > fim) {
    IntervaloVazio e;
    e.inicio = inicio;
    e.fim = fim;
    throw e;
  }
  inicio_ = inicio;
  fim_ = fim;
  elementos_ = new std::string[fim - inicio + 1];
}

void Vetor::atribuir(int i, std::string valor) {
  if (i < inicio_ || i > fim_) {
    IndiceInvalido e;
    e.inicio = inicio_;
    e.fim = fim_;
    e.indice = i;
    
    throw e;
  }

  elementos_[i - inicio_] = valor;
}

string Vetor::valor(int i) const {
  if (i < inicio_ || i > fim_) {
    IndiceInvalido e;
    e.inicio = inicio_;
    e.fim = fim_;
    e.indice = i;
    
    throw e;
  }

  if(&elementos_[i - inicio_] == nullptr) {
    IndiceNaoInicializado e;
    e.indice = i - inicio_;

    throw e;
  }

  return elementos_[i - inicio_];
}

Vetor::~Vetor() {
  delete[] elementos_;
}
