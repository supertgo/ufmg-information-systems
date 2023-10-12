#include "heap.hpp"

Heap::Heap(int maxsize) {
  tamanho = 0;
  data = new int[maxsize];
}

int Heap::Remover() {
  int root = data[0];
  data[0] = data[tamanho - 1];
  tamanho--;
  HeapifyPorBaixo(0);

  return root;
}

bool Heap::Vazio() { return tamanho == 0; }

int Heap::GetAncestral(int posicao) { return (posicao - 1) / 2; }

int Heap::GetSucessorEsq(int posicao) { return 2 * posicao + 1; }

int Heap::GetSucessorDir(int posicao) { return 2 * posicao + 2; }

void Heap::HeapifyPorBaixo(int posicao) {
  int l = GetSucessorEsq(posicao);
  int r = GetSucessorDir(posicao);
  int smallest = posicao;

  if (l < tamanho && data[l] < data[smallest])
    smallest = l;
  if (r < tamanho && data[r] < data[smallest])
    smallest = r;

  if (smallest != posicao) {
    int temp = data[posicao];
    data[posicao] = data[smallest];
    data[smallest] = temp;

    HeapifyPorBaixo(smallest);
  }
}

void Heap::Inserir(int x) {
  int i = tamanho;
  data[i] = x;
  int parent = GetAncestral(i);

  while (i != 0 && data[parent] > data[i]) {
    int temp = data[i];
    data[i] = data[parent];
    data[parent] = temp;

    i = parent;
    parent = GetAncestral(i);
  }

  tamanho++;
}

Heap::~Heap() {
  tamanho = 0;
  delete[] data;
}
