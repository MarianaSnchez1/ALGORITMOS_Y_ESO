//FastSort.cpp
#ifdef _FastSort_hpp_
#include <utility>
template <typename T>

//____________________EXTRA STUFF____________________
void display(vector<T> &a){
  cout <<"(" << a[0];
  for (unsigned i=1; i<a.size(); i++){
    cout << ", " << a[i];
  }
  cout << ")";
  cout << endl;
}

/*FOR HEAPSORT*/
template <typename T>
void percolateDown(vector<T> &a, int i, int n){
  int child;
  T tmp;
  for(tmp = a[i]; leftChild(i) < n; i = child){
    child = leftChild (i);
    if (child != n-1 && a[child] < a[child+1]){
      ++child;
    } if (tmp < a[child]){
      a[i] = a[child];
    } else{
      break;
    }
  }
  a[i] = tmp;
}

/*FOR MERGESORT*/
template <typename T>
void mergesort(vector <T> &a, vector<T> &tmp, int left, int right){
  if (left < right){
    int center = (left + right) / 2;
    mergesort(a, tmp, left, center);
    mergesort(a, tmp, center + 1, right);
    merge(a, tmp, left, center + 1, right);
  }
}

template <typename T>
void merge(vector<T> &a, vector<T> &tmp, int leftpos, int rightpos, int rightend){
  int leftend = rightpos - 1, tmppos = leftpos;
  int numelements = rightend - leftpos + 1;
  while (leftpos <= leftend && rightpos <=rightend){
    if (a[leftpos] <= a[rightpos]){
      tmp[tmppos++] = a[leftpos++];
    }else{
      tmp[tmppos++] = a[rightpos++];
    }
  } while (leftpos <= leftend){
    tmp[tmppos++] = a[leftpos++];
  } while (rightpos <= rightend){
    tmp[tmppos++] = a[rightpos++];
  }
  for (int i = 0; i < numelements; ++i, --rightend){
    a[rightend] = tmp[rightend];
  }
}

//____________________THE REAL SHIT _____________________
template <typename T>
void HeapSort(vector <T> &items){
  for(int i = items.size() / 2 - 1; i >= 0; --i){
    percolateDown(items, i, items.size());
  } for(int j = items.size() - 1; j > 0; --j){
    swap(items[0], items[j]);
    percolateDown(items,0,j);
  }
}


template <typename T>
void MergeSort(vector <T> &items){
  vector<T> tmparray (items.size());
  mergesort(items, tmparray, 0, items.size()-1);
}


/*
template <typename T>
void QuickSort(vector <T> &items)
*/

#endif
