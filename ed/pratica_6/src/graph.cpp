#include "graph.hpp"
#include "linked_list.hpp"
#include <iostream>
#include <sstream>
#include <string>

Grafo::Grafo() {
  std::string input_line;
  int neighboor, line_size;

  if (!std::getline(std::cin, input_line)) {
    throw std::runtime_error("Failed to read line");
  }

  int num_vertices = std::stoi(input_line);
  vertices.size = num_vertices;

  for (int i = 0; i < num_vertices; i++) {
    std::getline(std::cin, input_line);
    std::istringstream iss(input_line);

    if (!(iss >> line_size)) {
      throw std::runtime_error("Failed to read line size");
    }

    LinkedList<int> *neighbors = new LinkedList<int>();

    for (int j = 0; j < line_size; j++) {
      if (!(iss >> neighboor)) {
        throw std::runtime_error("Failed to read integer");
      }
      neighbors->push(neighboor);
    }
    vertices.push(neighbors);
  }
}

void Grafo::InsereVertice() {
  LinkedList<int> *new_list = new LinkedList<int>();
  this->vertices.push(new_list);
}
void Grafo::InsereAresta(int v, int w) {
  // if (v >= this->vertices-> || w >= this->vertice_num) {
  //   throw std::runtime_error("Invalid vertex");
  // }

  OuterNode *iterator = vertices.head;
  for (int i = 0; i < v; i++) {
    iterator = iterator->next;
  }

  iterator->innerList->push(w);
}

int Grafo::QuantidadeVertices() { return vertices.size; }
int Grafo::QuantidadeArestas() {
  int edges = 0;
  OuterNode *iterator = vertices.head;
  while (iterator != nullptr) {
    edges += iterator->innerList->size;
    iterator = iterator->next;
  }

  return edges / 2;
}

int Grafo::GrauMinimo() {
  OuterNode *iterator = vertices.head;
  int min = iterator->innerList->get_size();
  while (iterator != nullptr) {
    int grau = iterator->innerList->get_size();

    if (grau < min) {
      min = grau;
    }
    iterator = iterator->next;
  }

  return min;
}

int Grafo::GrauMaximo() {
  OuterNode *iterator = vertices.head;
  int max = iterator->innerList->get_size();
  while (iterator != nullptr) {
    int grau = iterator->innerList->get_size();

    if (grau > max) {
      max = grau;
    }
    iterator = iterator->next;
  }

  return max;
}

void Grafo::ImprimeVizinhos(int v) {
  OuterNode *iterator = vertices.head;

  for (int i = 0; i < v; i++) {
    iterator = iterator->next;
  }


  Node<int> *innerIterator = iterator->innerList->head;
  while (innerIterator != nullptr) {
    std::cout << innerIterator->data << " ";
    innerIterator = innerIterator->next;
  }
  std::cout << std::endl;
}

Grafo::~Grafo() { vertices.clear(); }
