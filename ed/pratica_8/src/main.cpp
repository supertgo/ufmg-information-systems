#include "unionFind.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int mst(Aresta *arestas, int num_vertices, int num_arestas) {
  std::vector<Aresta> mst;

  std::sort(arestas, arestas + num_arestas,
            [](const Aresta &a, const Aresta &b) { return a.custo < b.custo; });

  UnionFind uf(num_vertices);
  int count = 0;

  for (int i = 0; i < num_arestas; i++) {
    int u = arestas[i].u;
    int v = arestas[i].v;

    if (uf.Find(u) != uf.Find(v)) {
      mst.push_back(arestas[i]);
      uf.Union(u, v);
      count += arestas[i].custo;
    }
  }

  return count;
}

int main() {
  std::string input_line, edges_line;

  if (!std::getline(std::cin, input_line)) {
    throw std::runtime_error("Failed to read line");
  }

  std::istringstream ss(input_line);
  int vertices_count, edge_count;

  if (ss >> vertices_count >> edge_count) {
    Aresta *edges = new Aresta[edge_count];

    for (int i = 0; i < edge_count; i++) {
      std::getline(std::cin, edges_line);
      std::istringstream iss(edges_line);

      int u, v, weight;

      if (iss >> u >> v >> weight) {
        edges[i] = {u, v, weight};
      }
    }
    std::cout << mst(edges, vertices_count, edge_count) << std::endl;
    delete[] edges;
  } else {
    throw std::runtime_error("Failed to read line");
  }

  return 0;
}
