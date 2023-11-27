#ifndef NODE_H
#define NODE_H

#include <memory>
#include <string>
#include <list>

class Node {
public:
  std::string word;
  std::list<int> pages;
  std::shared_ptr<Node> left, right, parent;
  void update_height();

  int height;

  Node(std::string word, int page);
};
#endif // NODE_H
