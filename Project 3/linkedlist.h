#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

#include <utility>
#include <initializer_list>
using namespace std;

// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.

// TODO your code goes here:

template<typename T>
class LinkedList {

private:
  Node<T> *head;
  Node<T> *tail;
  int count;

public:
  LinkedList() : head(nullptr), tail(nullptr), count(0) {

  }

  LinkedList(initializer_list<T> list): head(nullptr), tail(nullptr), count(0) {

    for (const T &item : list) {
      push_back(item);
    }

  }

  // NodeIterator<T> &insert(NodeIterator<T> &iteratorElement, const T &element) {
  //
  //   Node<T>* newNode = new Node<T>();
  //   newNode -> data = element;
  //   newNode -> next = iteratorElement -> next;
  //   newNode -> previous = iteratorElement -> previous;
  //
  //   count += 1;
  //
  //   delete newNode;
  //   return iteratorElement;
  // }
  //
  // NodeIterator<T> &erase(NodeIterator<T> &iteratorElement) {
  //
  // }

  void push_front(const T & itemIn) {
    Node<T>* node = new Node<T>(itemIn);

    if (count == 0) {
      tail = node;
    } else {
      node -> next = head;
      head -> previous = node;
    }

    head = node;
    count += 1;

  }

  T & front() const {
    return head -> data;
  }

  void push_back(const T & itemIn) {
    Node<T> * node = new Node<T>(itemIn);

    if (count == 0) {
      head = node;
    } else {
      node -> previous = tail;
      tail -> next = node;
    }

    tail = node;
    count += 1;
  }

  T & back() const {
    return tail -> data;
  }

  int size() const {
    return count;
  }

  NodeIterator<T> begin() const {
      return NodeIterator<T>(head);
    }

  NodeIterator<T> end() const {
    return NodeIterator<T>(nullptr);
  }

  virtual ~LinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
      Node<T>* next = current -> next;
      delete current;
      current = next;
    }
    head = nullptr;
  }

  void reverse() {
    Node<T> *current = head;
    Node<T> *previous = nullptr;
    Node<T> *next = nullptr;

    while (current != nullptr) {
      next = current -> next;
      current -> next = previous;

      previous = current;
      current = next;
    }

    head = previous;
  }

};



// do not edit below this line

#endif
