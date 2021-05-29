//FastSort.hpp
#ifndef _FastSort_hpp_
#define _FastSort_hpp_
#include <iostream>
#include <vector>
using namespace std;

//____________________EXTRA STUFF____________________
template <typename T>
void display(vector<T> &a);

/*FOR HEAPSORT*/
int leftChild (int i){ return 2*i;}

template <typename T>
void percolateDown(vector<T> &a, int i, int n);

/*FOR MERGESORT*/
template <typename T>
void mergesort(vector <T> &a, vector<T> &tmp, int left, int right);

template <typename T>
void merge(vector<T> &a, vector<T> &tmp, int leftpos, int rightpos, int rightend);


//____________________THE REAL SHIT ____________________
template <typename T>
void SeapSort(vector <T> &items);

template <typename T>
void MergeSort(vector <T> &items);

template <typename T>
void QuickSort(vector <T> &items);


#include "FastSort.cpp"
#endif
