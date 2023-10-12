#include "heap.hpp"
#include <iostream>
#include <sstream>
#include <string>

int main() {
  std::string input_line;
  int node;
  if (!std::getline(std::cin, input_line)) {
    throw std::runtime_error("Failed to read line");
  }

  int heap_max_size = std::stoi(input_line);
  Heap heap = Heap(heap_max_size);

  std::getline(std::cin, input_line);
  std::istringstream iss(input_line);

  while (iss >> node)
    heap.Inserir(node);

  for (int j = 0; j < heap_max_size; j++) {
    std::cout << heap.Remover() << std::endl;
  }
  return 0;
}
