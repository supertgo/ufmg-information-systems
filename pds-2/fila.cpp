#include "fila.h"
#include <string>

Fila::Fila() {
  primeiro_ = nullptr;
  ultimo_ = nullptr;
}

std::string Fila::primeiro() { return primeiro_->chave; }

std::string Fila::ultimo() { return ultimo_->chave; }

bool Fila::vazia() {
  if (primeiro_ == nullptr)
    return true;

  return false;
}

void Fila::Inserir(std::string k) {
  No *last = new No{k, nullptr};

  if (tamanho() == 0) {
    primeiro_ = ultimo_ = last;
    return;
  }

  ultimo_->proximo = last;
  ultimo_ = last;
}

int Fila::tamanho() {
  No *iterator = primeiro_;
  int length = 0;

  while (iterator != nullptr) {
    length++;
    iterator = iterator->proximo;
  }

  delete iterator;
  return length;
}

void Fila::Remover() {
  No *elem_to_remove = primeiro_;

  if (tamanho() == 1) {
    ultimo_ = nullptr;
  }
  
  primeiro_ = primeiro_->proximo;

  delete elem_to_remove;
}

Fila::~Fila() {
  delete[] primeiro_;
  delete[] ultimo_;
}
