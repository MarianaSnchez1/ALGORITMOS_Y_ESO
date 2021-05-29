#ifndef __LIST_HPP
#define __LIST_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
struct Cell {
  T val;
  Cell *next;
  Cell *prev;
};

template <typename T>
class List {
private:
  Cell<T> *back;
  Cell<T> *front;
  int size;

public:
  List();
  ~List();

  bool empty();
  /**implement***/
  void push_back(T c);
  void pop_back();
  /**************/
  T get_back();
  /**implement***/
  void push_front(T c);
  void pop_front();
  /**************/
  T get_front();

  void display();
};

#include "list.cpp"

#endif
