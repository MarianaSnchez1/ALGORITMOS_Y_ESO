#ifndef _DUP_BST_HPP
#define _DUP_BST_HPP

#include <iostream>

template <typename T>
struct BSTNode {
  int reps;
  T key;
  BSTNode<T> *left;
  BSTNode<T> *right;
  BSTNode<T> *parent;
};


template <typename T>
class BST {
private:
  BSTNode<T> *root;

  void destroy_recursive(BSTNode<T> *node);
  BSTNode<T>* minimum(BSTNode<T> *node);
  BSTNode<T>* maximum(BSTNode<T> *node);
  BSTNode<T>* predecessor(BSTNode<T> *node);
  BSTNode<T>* successor(BSTNode<T> *node);
  void display_node(BSTNode<T> *node, int count);
  //void insert_node(BSTNode<T>* &node, BSTNode<T>* p, T k);
  //BSTNode<T>* find_node(BSTNode<T> *node, T k);
  //BSTNode<T>* remove_node(BSTNode<T>* &node, T k);
  //int capacity_recursive(BSTNode<T> *node, int &count);

public:
  BST() { root = nullptr; }
  ~BST() { destroy_recursive(root); }

  bool empty() { return root == nullptr; }
  //void display();
  //void insert(T k);
  //BSTNode<T>* find(T k);
  //BSTNode<T>* remove(T k);
  //int capacity();
};

#include "dup_bst.cpp"

#endif
