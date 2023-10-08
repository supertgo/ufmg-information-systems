#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

template<class T>
class Node {
public:
    Node* next;
    T data;
    Node(T data) : next(nullptr), data(data) {}
};


template<class T>
class LinkedList {
public:
    Node<T>* head;
    unsigned int size;

    LinkedList() {
        this->head = nullptr;
        this->size = 0;
    }
    void push(const T &item) {
      Node<T>* newNode = new Node<T>(item);
        
      if (this->head == nullptr) {
        this->head = newNode;
      } else {
      Node<T>* iterator = head;
      while(iterator->next != nullptr) {
        iterator = iterator->next;
      }
      iterator->next = newNode;
    }
      size++;
    }

    int get_size() const {
        return this->size;
    }
};

class OuterNode {
public:
    LinkedList<int>* innerList;
    OuterNode* next;

    OuterNode() : next(nullptr) {}
};

class OuterLinkedList {
public:
    OuterNode* head;
    int size;

    OuterLinkedList() : head(nullptr), size(0) {}

    void push(LinkedList<int>* innerList) {
      OuterNode* newNode = new OuterNode();
      newNode->innerList = innerList;

      if (head == nullptr) {
          head = newNode;
      } else {
          OuterNode* temp = head;
          while (temp->next != nullptr) {
              temp = temp->next;
          }
          temp->next = newNode;
      }
    }

  void clear() {
        OuterNode* current = head;
        while (current != nullptr) {
            OuterNode* next = current->next;
            
            delete current->innerList;

            delete current;

            current = next;
        }

        head = nullptr;
    }
};


#endif //_LINKEDLIST_H
