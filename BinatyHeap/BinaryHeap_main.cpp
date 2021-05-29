#include "BinaryHeap.hpp"

int main(){
  cout << boolalpha;
  BinaryHeap<int> fernando;

  for (int i=0; i<16; i+=2){
    fernando.insert(i);
  }
  int x = 44;
  fernando.insert(x);
  x = 21;
  fernando.insert(x);

  fernando.display();
  cout << endl;
  cout << "QAAAA " << fernando.check_heap_order() << endl;

  cout << "Deleting " << fernando.findMin() << endl;
  cout << endl;

  fernando.deleteMin();
  fernando.display();
  cout << "QAAAA " << fernando.check_heap_order() << endl;

  cout << endl;
  cout<< "Tryhard heapsort" << endl;
  fernando.heapsort();

  cout << "Result: ";
  fernando.display();

  cout << "QAAAA " << fernando.check_heap_order() << endl;

  return 0;
}
