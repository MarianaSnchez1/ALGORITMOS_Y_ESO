//Biary heap.hpp
#ifndef _maxBinaryHeap_hpp_
#define _maxBinaryHeap_hpp_

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

template <typename K>
class maxBinaryHeap {
private:
  int count;
  vector<K> array;
  //void buildHeap();
  void percolateDown (int hole);
  int rightChild (int i){ return 2*i+1;}
  int leftChild (int i){ return 2*i;}
  void newperc (vector<K> &a, int i, int n);

public:
  maxBinaryHeap (int capacity = 100);
  maxBinaryHeap (const vector<K> &items);

  ~maxBinaryHeap();

  const K &findMax()const;
  void insert(K &x);
  void deleteMax();

  bool empty();
  void clear();
  void display();

  void heapsort();
};



#include "maxBinaryHeap.cpp"
#endif
