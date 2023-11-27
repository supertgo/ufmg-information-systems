#include "set.h"
#include <iostream>

StringSet::StringSet(int tamanho) {
  this->tamanhoOriginal = tamanho;
  this->tamanhoTabela = tamanho;
  this->tamanhoConjunto = 0;
  this->tabela = new ElementoTabela[tamanho];

  for (int i = 0; i < tamanho; i++) {
    this->tabela[i].vazio = true;
    this->tabela[i].retirada = false;
  }
}

int findNextEmptyPositionInArray(ElementoTabela *v, int size, int position) {
  bool hasPassedForAllPositions = false;

  for (int i = position; i < size || !hasPassedForAllPositions;
       i = (i + 1) % size) {
    if (v[i].retirada || v[i].vazio) {
      return i;
    }

    if (i == position) {
      hasPassedForAllPositions = true;
    }
  }

  return -1;
}

StringSet::~StringSet() { delete[] tabela; }

void StringSet::Resize(size_t tamanho) {
  ElementoTabela *newTable = new ElementoTabela[tamanho];

  for (size_t i = 0; i < tamanho; i++) {
    newTable[i].vazio = true;
  }

  for (int i = 0; i < this->tamanhoTabela; i++) {
    if (!(this->tabela[i].retirada) && !this->tabela[i].vazio) {
      newTable[findNextEmptyPositionInArray(
          newTable, tamanho, Hash(this->tabela[i].dado))] = this->tabela[i];
    }
  }

  delete[] tabela;
  this->tabela = newTable;
  this->tamanhoTabela = tamanho;
}

void StringSet::Rehash(int pos) { Inserir(this->tabela[pos].dado); }

void StringSet::Inserir(string s) {
  if (Pertence(s)) {
    return;
  }

  if (this->tamanhoConjunto == (this->tamanhoTabela / 2) + 1) {
    Resize(this->tamanhoTabela * 2);
  }

  int pos = findNextEmptyPosition(Hash(s));

  if (pos == -1) {
    return;
  }

  this->tabela[pos].dado = s;
  this->tabela[pos].vazio = false;
  this->tabela[pos].retirada = false;

  this->tamanhoConjunto++;
}

void StringSet::Imprimir() {
  if (this->tamanhoConjunto == 0) {
    std::cout << "{ }" << std::endl;
    return;
  }

  string content[this->tamanhoConjunto];
  int pos = 0;

  for (int i = 0; i < this->tamanhoTabela; i++) {
    if (!this->tabela[i].retirada && !this->tabela[i].vazio) {
      content[pos] = this->tabela[i].dado;
      pos++;
    }
  }
  std::cout << "{ ";
  for (int i = 0; i < this->tamanhoConjunto - 1; i++) {
    std::cout << content[i] << ", ";
  }

  std::cout << content[tamanhoConjunto - 1] << " }" << std::endl;
}

StringSet *StringSet::Uniao(StringSet *s) {
  StringSet *unionSet = new StringSet(this->tamanhoTabela + s->tamanhoTabela);

  for (int j = 0; j < this->tamanhoTabela; j++) {
    if (!(this->tabela[j].vazio) && !(this->tabela[j].retirada)) {
      unionSet->Inserir(this->tabela[j].dado);
    }
  }

  for (int i = 0; i < s->tamanhoTabela; i++) {
    if (!(s->tabela[i].vazio) && !(s->tabela[i].retirada)) {
      unionSet->Inserir(s->tabela[i].dado);
    }
  }

  return unionSet;
}

StringSet *StringSet::DiferencaSimetrica(StringSet *S) {
  StringSet *result = Uniao(S);

  for (int i = 0; i < result->tamanhoTabela; i++) {
    if (!(result->tabela[i].vazio) && !(result->tabela[i].retirada) &&
        S->Pertence(result->tabela[i].dado) &&
        this->Pertence(result->tabela[i].dado)) {
      result->Remover(result->tabela[i].dado);
    }
  }

  return result;
}

void StringSet::Remover(string s) {
  int position = Hash(s);

  if (this->tabela[position].dado == s && !(this->tabela[position].retirada)) {
    this->tabela[position].retirada = true;
    this->tabela[position].vazio = true;
    this->tamanhoConjunto--;
    return;
  }

  bool hasPassedForAllPositions = false;

  for (int i = (position + 1) % this->tamanhoTabela; i != position;
       i = (i + 1) % this->tamanhoTabela) {
    if (!hasPassedForAllPositions) {
      if (!(this->tabela[i].retirada) && this->tabela[i].dado == s) {
        this->tabela[i].retirada = true;
        this->tamanhoConjunto--;
        return;
      }

      if (i == (this->tamanhoTabela - 1 + position) % this->tamanhoTabela) {
        hasPassedForAllPositions = true;
      }
    } else {
      break;
    }
  }
}

StringSet *StringSet::Intersecao(StringSet *S) {
  StringSet *intersection = new StringSet(
      this->tamanhoTabela >= S->tamanhoTabela ? S->tamanhoTabela
                                              : this->tamanhoTabela);

  for (int i = 0; i < this->tamanhoTabela; i++) {
    if (!(this->tabela[i].vazio) && !(this->tabela[i].retirada) &&
        S->Pertence(this->tabela[i].dado)) {
      intersection->Inserir(this->tabela[i].dado);
    }
  }

  return intersection;
}

int StringSet::findNextEmptyPosition(int position) {
  bool hasPassedForAllPositions = false;

  for (int i = position; i < this->tamanhoTabela || !hasPassedForAllPositions;
       i = (i + 1) % this->tamanhoTabela) {
    if (this->tabela[i].retirada || this->tabela[i].vazio) {
      return i;
    }

    if (i == position) {
      hasPassedForAllPositions = true;
    }
  }

  return -1;
}

int StringSet::Find(string s) {
  int position = Hash(s);

  if (this->tabela[position].dado == s && !(this->tabela[position].retirada)) {
    return position;
  }

  bool hasPassedForAllPositions = false;

  for (int i = (position + 1) % this->tamanhoTabela; i != position;
       i = (i + 1) % this->tamanhoTabela) {
    if (!hasPassedForAllPositions) {
      if ((!(this->tabela[i].retirada) || !(this->tabela[i].vazio)) &&
          this->tabela[i].dado == s) {
        return i;
      }

      if (i == (this->tamanhoTabela - 1 + position) % this->tamanhoTabela) {
        hasPassedForAllPositions = true;
      }
    } else {
      break;
    }
  }

  return -1;
}

bool StringSet::Pertence(string s) {
  int position = Find(s);

  if (position == -1) {
    return false;
  }

  return true;
}

int StringSet::Hash(string s) {
  int sum = 0;

  for (char c : s) {
    sum += static_cast<int>(c);
  }

  return sum % this->tamanhoTabela;
}
