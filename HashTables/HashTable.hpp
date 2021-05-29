#ifndef _hash_table_hpp_
#define _hash_table_hpp_

#include <iostream>
#include <string>

using namespace std;

const int TABLE_SIZE = 101;
const int MAX_LOAD_FACTOR = 1;

template <typename VT>
struct Node{
  string key;
  VT value;
  Node<VT> *next;
};

template <typename VT>
class HashTable{

private:

  Node<VT> **buckets;
  int nBuckets;
  int count;
  float load_factor;

  Node<VT> * search_bucket(int index, string key){
    Node<VT> *recor;
    recor = buckets[index];

    while(recor != nullptr){
      if (recor->key == key){
        return recor;
      }
      recor = recor->next;
    }

    return recor;
  }

  unsigned int hash(string key){
    unsigned int hashVal = 0;
    for (char ch : key){
      hashVal += ch;
    }
    return hashVal % TABLE_SIZE;
  }


public:
  HashTable();
  ~HashTable();

  int size();
  bool empty();
  void clear();

  float load_factor_ret();

  VT get(string key);

  bool search(string key);

  bool insert(string key, VT value);

  void remove(string key);

  void display();
};

#include "HashTable.cpp"
#endif /*slist_hpp */
