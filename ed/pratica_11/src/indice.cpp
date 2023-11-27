#include "../include/avl.h"
#include <iostream>
#include <string>
#define MAXPALAVRA 10
#define MAXINDICE 10
#define MAXPAGINA 10

int main(int argc, char **argv) {
  std::string word;
  int page;

  auto tree = Avl();

  while (std::cin >> word >> page) {
    tree.root = tree.insert(tree.root, word, page);
  }

  tree.print_tree(tree.root);
  return 0;
}
