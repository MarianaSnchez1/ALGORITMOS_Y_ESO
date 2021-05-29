//Biary heap.hpp
#ifndef _BinaryHeap_hpp_
#define _BinaryHeap_hpp_

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

template <typename K>
class BinaryHeap {
private:
  int count;
  vector<K> array;
  //void buildHeap();
  void percolateDown (int hole);
  int leftChild (int i){ return 2*i;}
  void newperc (vector<K> &a, int i, int n);

public:
  BinaryHeap (int capacity = 100);
  BinaryHeap (const vector<K> &items);

  ~BinaryHeap();

  const K &findMin()const;
  void insert(K &x);
  void deleteMin();

  bool empty();
  void clear();
  void display();

  void heapsort();

  bool check_heap_order ();
};

#include "BinaryHeap.cpp"
#endif
