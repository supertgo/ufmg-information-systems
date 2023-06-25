#include "dicionario.h"
#include <list>

Dicionario::Dicionario() { elementos_ = std::list<Elemento>(); }

int Dicionario::tamanho() { return elementos_.size(); }

bool Dicionario::pertence(string chave) {
  for (std::list<Elemento>::iterator it = elementos_.begin();
       it != elementos_.end(); it++) {
    if (it->chave == chave) {
      return true;
    }
  }

  return false;
}

string Dicionario::menor() {
  if (tamanho() == 0) {
    DicionarioVazio e;
    throw e;
  }
  string menor = elementos_.begin()->chave;

  for (std::list<Elemento>::iterator it = elementos_.begin();
       it != elementos_.end(); it++) {
    if (it->chave < menor) {
      menor = it->chave;
    }
  }

  return menor;
}

string Dicionario::valor(string chave) {
  for (std::list<Elemento>::iterator it = elementos_.begin();
       it != elementos_.end(); it++) {
    if (it->chave == chave) {
      return it->valor;
    }
  }

  ChaveInexistente e;
  e.chave = chave;
  throw e;
}

void Dicionario::Inserir(string chave, string valor) {
  if (pertence(chave)) {
    ChaveRepetida e;
    e.chave = chave;

    throw e;
  }

  Elemento *newNode = new Elemento{chave, valor};
  elementos_.push_back(*newNode);
}

void Dicionario::Remover(string chave) {
  for (std::list<Elemento>::iterator it = elementos_.begin();
       it != elementos_.end(); ++it) {
    if (it->chave == chave) {
      it = elementos_.erase(it);
      return;
    }
  }

  ChaveInexistente e;
  e.chave = chave;

  throw e;
}

void Dicionario::Alterar(string chave, string valor) {
  for (std::list<Elemento>::iterator it = elementos_.begin();
       it != elementos_.end(); it++) {
    if (it->chave == chave) {
      it->valor = valor;
      return;
    }
  }

  ChaveInexistente e;
  e.chave = chave;

  throw e;
}

Dicionario::~Dicionario() {
}
