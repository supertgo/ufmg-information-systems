#include "fila_de_prioridade.h"

#include <list>
#include <string>
#include <vector>

using std::string;
using std::vector;

void FilaDePrioridade::Adicionar(Pessoa p) {
  if (lista_.size() == 0) {
    lista_.push_back(p);
    return;
  } else {
      for (list<Pessoa>::iterator it=lista_.begin(); it != lista_.end(); it++) {
        if (it->prioridade < p.prioridade) {
          lista_.insert(it, p);
          return;
        } else {
          while (it->prioridade >= p.prioridade && it != lista_.end()) {
            it++;
          }
          lista_.insert(it, p);
          return;
        }
      }
  }
  lista_.push_back(p);
}

string FilaDePrioridade::RemoverMaiorPrioridade() {
  string nome;
  if (lista_.size() > 0) {
    nome = lista_.front().nome;
    lista_.pop_front();
  }
  return nome;
}


void FilaDePrioridade::Remover(string nome) {
  for (list<Pessoa>::iterator it=lista_.begin(); it != lista_.end(); it++) {
    if (it->nome == nome) {
        lista_.erase(it);
        return;
    }
  }
}


int FilaDePrioridade::tamanho() {
  return lista_.size();
}

vector<string> FilaDePrioridade::listar() {
  vector<string> v;

  for (list<Pessoa>::iterator it=lista_.begin(); it != lista_.end(); it++) {
    v.push_back(it->nome);
  }

  return v; 
}

