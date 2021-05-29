#include "maxBinaryHeap.hpp"

int main(){

  maxBinaryHeap<int> anastacio;

  for (int i=1; i<16; i+=2){
    anastacio.insert(i);
  }

  int x = 44;
  anastacio.insert(x);
  x = 21;
  anastacio.insert(x);

  anastacio.display();
  cout << endl;

  cout << "Deleting " << anastacio.findMax() << endl;
  cout << endl;

  anastacio.deleteMax();
  anastacio.display();

  cout << endl;
  cout << "Tryhard again heapsort" << endl;
  anastacio.heapsort();
  anastacio.display();
  return 0;
}
