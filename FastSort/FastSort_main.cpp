//fast_sort_main.cpp
#include "FastSort.hpp"

int main(){
  vector<int> tres {7,2,16,4,5,9,3};
  vector<int> foca = tres;

  cout << "Normal vec: ";
  display(tres);

  HeapSort(tres);
  cout << "Organized with heap sort: ";
  display(tres);

  MergeSort(foca);
  cout << "Organized with merge sort: ";
  display(foca);

  return 0;
}
