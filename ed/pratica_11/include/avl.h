#ifndef AVLTREE_H
#define AVLTREE_H

#include "node.h"
#include <memory>

class Avl {
public:
  std::shared_ptr<Node> root;

  Avl();

  ~Avl();

  int height(std::shared_ptr<Node> node);
  int balance_factor(std::shared_ptr<Node> node);

  std::shared_ptr<Node> insert(std::shared_ptr<Node> node,
                                    std::string word, int page);
  std::shared_ptr<Node> rotate_to_right(std::shared_ptr<Node> node);
  std::shared_ptr<Node> rotate_to_left(std::shared_ptr<Node> node);
  std::shared_ptr<Node> rotate_to_left_then_right(std::shared_ptr<Node> node);
  std::shared_ptr<Node> rotate_to_right_then_left(std::shared_ptr<Node> node);

  bool is_build();

  void print_tree(std::shared_ptr<Node> node);

  void destroy(Node *node);

  void evaluate(Node *node, unsigned int level);

  Node *get_root() const;
};

#endif // AVLTREE_H
