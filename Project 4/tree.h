#ifndef TREE_H
#define TREE_H

#include "treenode.h"

// TODO your code goes here:
template<typename T>
class BinarySearchTree {

private:
  unique_ptr<TreeNode<T>> root;

public:
  BinarySearchTree(){

  }

  BinarySearchTree(BinarySearchTree &bst) : root(bst.root.get()){

  }

  // BinarySearchTree &operator =(const BinarySearchTree &bst) {
  //   root.reset();
  //   copy(bst.root.get());
  //   return *this;
  // }
  //
  // TreeNode<T>* copy(TreeNode<T> * t) const {
  //
  //   if (t == nullptr) {
  //     return nullptr;
  //   }
  //
  //   TreeNode<T> *copyNode = new TreeNode<T>(t -> data);
  //
  //   //copyNode -> data = t -> data;
  //   copyNode -> setLeftChild(t);
  //   copyNode -> setRightChild(t);
  //
  //   return copyNode;
  //
  // }

  ostream &write (ostream &o) const {
    root -> write(o);
    return o;
  }

  TreeNode<T>* insert(const T & dataIn) {
    TreeNode<T> *newNode = new TreeNode<T>(dataIn);
    TreeNode<T> *nodeRoot = root.get();

    if (nodeRoot == nullptr) {
      newNode -> leftChild = nullptr;
      newNode -> rightChild = nullptr;

      root.reset(newNode);
      nodeRoot = newNode;
      return newNode;

    } else {

      while (nodeRoot != nullptr) {
        if (dataIn < nodeRoot -> data) {
          if (nodeRoot -> leftChild == nullptr) {

            nodeRoot -> setLeftChild(newNode);
            nodeRoot = newNode;

            return newNode;
          } else {
            nodeRoot = root.get() -> leftChild.get();
          }
        } else if (nodeRoot -> data  < dataIn) {
            if (nodeRoot -> rightChild == nullptr) {

              nodeRoot -> setRightChild(newNode);
              nodeRoot = newNode;

              return newNode;
            } else {
              nodeRoot = root.get() -> rightChild.get();
            }
        } else {
          return nullptr;
        }
      }
    }
    return nodeRoot;

  }

  TreeNode<T>* find(const T & findDataIn) {
    //TreeNode<T> *newNode = new TreeNode<T>(findDataIn);
    TreeNode<T> *nodeRoot = root.get();

    if (nodeRoot == nullptr) {
      return nullptr;
    } while (nodeRoot != nullptr) {
        if (findDataIn < nodeRoot -> data) {
          if (nodeRoot -> leftChild == nullptr) {
            return nullptr;
          } else {
              nodeRoot = nodeRoot -> leftChild.get();
          }
        } else if (nodeRoot -> data < findDataIn) {
          if (nodeRoot -> rightChild == nullptr) {
            return nullptr;
          } else {
              nodeRoot = nodeRoot -> rightChild.get();
          }
        } else {
          return nodeRoot;
        }
    }
    return nullptr;
  }


};



// do not edit below this line

#endif
