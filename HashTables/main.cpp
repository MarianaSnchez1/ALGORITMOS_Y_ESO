#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <iomanip>
#include "HashTable.hpp"


using namespace std;

int main(){

  cout << boolalpha;

  HashTable<int> ht;

  cout << "EMPTY? " <<ht.empty() << endl;

  cout << "Size: " << ht.size() << endl;

  cout << "Esta?: " << ht.search("a") << endl;

  cout << "INSERT: " << ht.insert("a",5) << endl;

  cout << "INSERT: " << ht.insert("b",7) << endl;

  cout << "INSERT: " << ht.insert("c",10) << endl;

  cout << "INSERT: " << ht.insert("d",2) << endl;

  cout << "INSERT: " << ht.insert("a",3) << endl;

  cout << endl;
  cout << endl;
  cout << endl;

  //ht.display();

  cout << endl;
  cout << endl;
  cout << endl;

  cout << ht.get("a") << endl;

  ht.remove("d");

  cout << "Size: " << ht.size() << endl;

  cout << ht.load_factor_ret() << endl;

  //ht.display();


  return 0;
}
