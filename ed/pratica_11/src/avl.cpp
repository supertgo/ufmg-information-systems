#include <utility>

#include "../include/avl.h"
#include "../include/node.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

int Avl::height(std::shared_ptr<Node> node) {
  return node == nullptr
             ? 0
             : 1 + std::max(height(node->left), height(node->right));
}

int Avl::balance_factor(std::shared_ptr<Node> node) {
  return node == nullptr ? 0 : height(node->left) - height(node->right);
}

void Node::update_height() {
  int left_height = left ? left->height : 0;
  int right_height = right ? right->height : 0;
  this->height = 1 + std::max(left_height, right_height);
}

Node::Node(std::string word, int page) {
  this->word = word;
  this->pages.push_back(page);
  this->left = this->right = this->parent = nullptr;
  this->height = 1;
}

std::shared_ptr<Node> Avl::rotate_to_right(std::shared_ptr<Node> node) {
  auto new_root = node->left;
  node->left = new_root->right;
  new_root->right = node;

  new_root->parent = node->parent;
  node->parent = new_root;
  if (node->left != nullptr) {
    node->left->parent = node;
  }

  node->update_height();
  new_root->update_height();

  return new_root;
}

std::shared_ptr<Node> Avl::rotate_to_left(std::shared_ptr<Node> node) {
  auto new_root = node->right;
  node->right = new_root->left;
  new_root->left = node;

  new_root->parent = node->parent;
  node->parent = new_root;
  if (node->right != nullptr) {
    node->right->parent = node;
  }

  node->update_height();
  new_root->update_height();

  return new_root;
}

std::shared_ptr<Node>
Avl::rotate_to_left_then_right(std::shared_ptr<Node> node) {
  node->left = rotate_to_left(node->left);
  return rotate_to_right(node);
}

std::shared_ptr<Node>
Avl::rotate_to_right_then_left(std::shared_ptr<Node> node) {
  node->right = rotate_to_right(node->right);
  return rotate_to_left(node);
}

std::shared_ptr<Node> Avl::insert(std::shared_ptr<Node> node, std::string word,
                                  int page) {
  if (node == nullptr) {
    return std::make_shared<Node>(word, page);
  }

  if (word < node->word) {
    node->left = insert(node->left, word, page);
    node->left->parent = node;
  } else if (word > node->word) {
    node->right = insert(node->right, word, page);
    node->right->parent = node;
  } else {
    if (std::find(node->pages.begin(), node->pages.end(), page) ==
        node->pages.end()) {
      node->pages.push_back(page);
      node->pages.sort(); // Keep the list of pages sorted
    }
    return node;
  }

  // 2. Update height of this ancestor node
  node->height = 1 + std::max(height(node->left), height(node->right));

  // 3. Get the balance factor of this ancestor node to check whether this node
  // became unbalanced
  int balance = balance_factor(node);

  // If this node becomes unbalanced, then there are 4 cases

  // Left Left Case
  if (balance > 1 && word < node->left->word) {
    return rotate_to_right(node);
  }

  // Right Right Case
  if (balance < -1 && word > node->right->word) {
    return rotate_to_left(node);
  }

  // Left Right Case
  if (balance > 1 && word > node->left->word) {
    node->left = rotate_to_left(node->left);
    return rotate_to_right(node);
  }

  // Right Left Case
  if (balance < -1 && word < node->right->word) {
    node->right = rotate_to_right(node->right);
    return rotate_to_left(node);
  }

  // return the (unchanged) node pointer
  return node;
}

Avl::Avl() { this->root = nullptr; }

Avl::~Avl() = default;

void Avl::print_tree(std::shared_ptr<Node> node) {
  if (node != nullptr) {
    print_tree(node->left);

    std::cout << node->word << ": ";
    for (int page : node->pages) {
      std::cout << page << " ";
    }
    std::cout << std::endl;

    print_tree(node->right);
  }
}
