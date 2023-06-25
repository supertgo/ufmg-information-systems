#include "Estoque.hpp"
#include <iostream>
#include <string>

void Estoque::add_mercadoria(const std::string &mercadoria, unsigned int qtd) {
  estoque_[mercadoria] += qtd;
}

void Estoque::sub_mercadoria(const std::string &mercadoria, unsigned int qtd) {
  if (estoque_.count(mercadoria) == 0) {
    std::cout << mercadoria << " inexistente" << std::endl;
    return;
  }

  if (estoque_[mercadoria] < qtd) {
    std::cout << mercadoria << " insuficiente" << std::endl;
    return;
  }

  estoque_[mercadoria] -= qtd;
}

unsigned int Estoque::get_qtd(const std::string &mercadoria) const {
  if (estoque_.count(mercadoria) == 0) {
    return 0;
  }

  return estoque_.at(mercadoria);
}

void Estoque::imprime_estoque() const {
  for (const auto &item : estoque_) {
    std::cout << item.first << ", " << item.second << std::endl;
  }
}

Estoque &Estoque::operator+=(const Estoque &rhs) {
  for (const auto &item : rhs.estoque_) {
    estoque_[item.first] += item.second;
  }

  return *this;
}

Estoque &Estoque::operator-=(const Estoque &rhs) {
  for (const auto &item : rhs.estoque_) {
    if (estoque_.count(item.first) != 0) {
      estoque_[item.first] -= item.second;
      if (estoque_[item.first] <= 0) {
        estoque_.erase(item.first);
      }
    }
  }

  return *this;
}

bool operator<(Estoque &lhs, Estoque &rhs) {
  for (const auto &item : lhs.estoque_) {
    if (rhs.estoque_.count(item.first) == 0 ||
        item.second >= rhs.estoque_.at(item.first)) {

      return false;
    }
  }
  return true;
}

bool operator>(Estoque &lhs, Estoque &rhs) { return rhs < lhs; }
