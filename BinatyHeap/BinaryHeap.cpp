//Biary heap.cpp
#ifdef _BinaryHeap_hpp_
#include <utility>

/*_________ PRIVATE_________*/
template <typename K>
void BinaryHeap<K>::percolateDown (int h){
  while(array[h] > array[h*2] || array[h] > array[h*2+1]){
    if (array[h*2] < array[h*2+1] && h*2 <= count){
      swap(array[h], array[h*2]);
      h *= 2;
    } else if (h*2+1 <= count){
      swap(array[h*2+1], array[h]);
      h = h*2+1;
    } else{
      return;
    }
  }
}

template <typename K>
void BinaryHeap<K>::newperc(vector<K> &a, int i, int n){
  int child;
  K tmp;
  for (tmp = a[i]; leftChild(i) < n; i=child){
    child = leftChild (i);
    if (child != n-1 && a[child]<a[child+1]){
      ++child;
    } if (tmp < a[child]){
      a[i] = a[child];
    } else{
      break;
    }
  }
  a[i] = tmp;
}

/*_________CONSTRUCTOR/DESTRUCTOR_________*/
template <typename K>
BinaryHeap<K>::BinaryHeap (int capacity){
  count = 0;
  array.reserve(capacity);
  array.push_back(K{});
}

template <typename K>
BinaryHeap<K>::BinaryHeap (const vector<K> &items){
  insert(K{});
  for (unsigned i=0; i< items.size(); i++){
    insert (items[i]);
  }
}

template <typename K>
BinaryHeap<K>::~BinaryHeap (){
  cout << "THE END" << endl;
  clear();
}


/*_________PUBLIC_________*/
template <typename K>
const K & BinaryHeap<K>::findMin()const{
  if (count > 0){
    return array[1];
  } else{
    cout << "No min on empty heap" << endl;
    exit(1);
  }
}

template <typename K>
void BinaryHeap<K>::insert(K &x){
  array.push_back (x);
  count++;
  for (int i=count; i>1; i=i/2){
    if (array[i] < array[i/2]){
      swap(array[i], array[i/2]);
    }
  }
}

template <typename K>
void BinaryHeap<K>::deleteMin(){
  if (count == 0){
    cout << "No min on empty heap" << endl;
    exit(1);
  }
  swap(array[1],array[count]);
  array.pop_back();
  count--;
  percolateDown(1);
}

template <typename K>
bool BinaryHeap<K>::empty(){
  return count==0;
}

template <typename K>
void BinaryHeap<K>::clear(){
}

template <typename K>
void BinaryHeap<K>::display(){
  cout << "Normal BinaryHeap:" << endl;
  for (int i=1; i<= count; i++){
    cout << i << "  " << array[i] << endl;
  }
}

template <typename K>
void BinaryHeap<K>::heapsort(){
  for (int i = array.size()/2-1; i>0; --i){
    newperc(array,i,array.size());
  } for(int j=array.size()-1; j>1; --j){
    swap(array[1], array[j]);
    newperc(array,1,j);
  }
}

template <typename K>
bool BinaryHeap<K>::check_heap_order (){
  int end = array.size()-1;
  for (unsigned i = 1; i<array.size(); i++){
    int child1 = i*2;
    int child2 = i*2 + 1;
    if (end >= array[child2]){
       if (array[i] > array[child1] || array[i] > array[child2]) return false;
       if (array[child1] > array[child2]) return false;
    }
  }
  return true;
}
#endif
