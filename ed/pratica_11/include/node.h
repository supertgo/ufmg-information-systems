#ifndef NODE_H
#define NODE_H

#include <memory>
#include <string>
#include <vector>

class Node {
public:
  std::string word;
  std::vector<int> pages;
  std::shared_ptr<Node> left, right;
  void update_height();

  int height;

  Node(std::string word, int page);
};
#endif // NODE_H
