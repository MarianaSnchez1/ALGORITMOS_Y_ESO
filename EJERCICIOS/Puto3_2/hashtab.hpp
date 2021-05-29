#ifndef __HASHMAP_HPP
#define __HASHMAP_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

const int TABLE_SIZE = 10;

struct KeyNode {
  vector<int> key;
  KeyNode *next;
};

class HashTab {
private: 
  KeyNode **table;
  int tableSize;
  int count;

  bool compare_keys(const vector<int> &key1, const vector<int> &key2);
  KeyNode* find_key(KeyNode* tmp, const vector<int> &key);
  KeyNode* find_in_bucket(unsigned int i, const vector<int> &key);
  void rehash(int max);

  /********************************/
  unsigned int hash(const vector<int> &key);
  /********************************/
  
public:
  HashTab();
  ~HashTab();

  int size();
  bool empty();
  void insert(const vector<int> &key);
  void remove(const vector<int> &key);
  bool find(const vector<int> &key);

  /********************************/
  void display_bucket(int i);
  /********************************/
};

ostream& operator<<(ostream &os, vector<int> &v);

#endif
