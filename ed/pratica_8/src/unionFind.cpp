#include "unionFind.hpp"

UnionFind::UnionFind(int size) {
  subconjuntos = new Subconjunto[size];
  tamanho = size;

  for (int i = 0; i < size; i++) {
    subconjuntos[i].representante = i;
    subconjuntos[i].rank = 0;
  }
}

UnionFind::~UnionFind() { delete[] subconjuntos; }

void UnionFind::Make(int x) {
  if (x >= 0 || x < tamanho) {
    subconjuntos[x].representante = x;
    subconjuntos[x].rank = 0;
  }
}

int UnionFind::Find(int x) {
  if (subconjuntos[x].representante != x) {
    subconjuntos[x].representante = Find(subconjuntos[x].representante);
  }

  return subconjuntos[x].representante;
}

void UnionFind::Union(int a, int b) {
  int x = Find(a);
  int y = Find(b);

  if (x == y) {
    return;
  }

  if (subconjuntos[x].rank < subconjuntos[y].rank) {
    subconjuntos[x].representante = y;
  } else if (subconjuntos[x].rank > subconjuntos[y].rank) {
    subconjuntos[y].representante = x;
  } else {
    subconjuntos[y].representante = x;
    subconjuntos[x].rank++;
  }
}
