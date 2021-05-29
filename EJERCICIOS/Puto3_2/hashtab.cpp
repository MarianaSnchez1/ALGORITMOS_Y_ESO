#include "hashtab.hpp"
#include <cstdlib>
HashTab::HashTab() {
  count = 0;
  tableSize = TABLE_SIZE;
  table = new KeyNode*[tableSize];
  for(int i = 0; i < tableSize; i++)
    table[i] = nullptr;
}

HashTab::~HashTab() {
  KeyNode *tmp;
  for(int i = 0; i < tableSize; ++i){
    tmp = table[i];
    while(tmp != nullptr){
      table[i] = table[i]->next;
      delete tmp;
      tmp = table[i];
    }
  }
  delete[] table;
}

int HashTab::size() {
  return count;
}

bool HashTab::empty() {
  return count == 0;
}

bool HashTab::compare_keys(const vector<int> &key1, const vector<int> &key2) {
  if(key1.size() != key2.size())
    return false;
  for(int i = 0; i < key1.size(); i++){
    if(key1[i] != key2[i])
      return false;
  }
  return true;
}

KeyNode* HashTab::find_key(KeyNode* tmp, const vector<int> &key) {
  if(tmp == nullptr)
    return nullptr;
  else if(compare_keys(tmp->key,key))
    return tmp;
  else
    return find_key(tmp->next, key);
}

KeyNode* HashTab::find_in_bucket(unsigned int i, const vector<int> &key) {
  return find_key(table[i], key);
}

void HashTab::insert(const vector<int> &key) {
  unsigned int bucket = hash(key);
  if(bucket > tableSize-1) rehash(bucket);
  KeyNode* tmp = find_in_bucket(bucket, key);

  if(tmp == nullptr){
    tmp = new KeyNode;
    tmp->key = key;
    tmp->next = table[bucket];
    table[bucket] = tmp;
    count++;
    //cout << "Insertando llave " << tmp->key << endl;
  }
}

bool HashTab::find(const vector<int> &key) {
  unsigned int bucket = hash(key);
  KeyNode* tmp = find_in_bucket(bucket, key);
  if(tmp == nullptr)
    return false;
  else
    return true;
}

void HashTab::remove(const vector<int> &key) {
  unsigned int bucket = hash(key);
  KeyNode* tmp = table[bucket];
  if(tmp != nullptr){
    if(compare_keys(tmp->key,key)){
      table[bucket] = tmp->next;
      delete tmp;
      count--;
    }else{
      while(true){
	KeyNode* nxt = tmp->next;
	if(nxt != nullptr && compare_keys(nxt->key,key)){
	  tmp->next = nxt->next;
	  delete nxt;
	  count--;
	  break;
	}else
	  throw runtime_error("remove: key not found in array");
	tmp = nxt;
      }
    }
  }else
    throw runtime_error("remove: key not found in array");
}

void HashTab::rehash(int max) {
  cout << "rehashing!\n";
  int oldTableSize = tableSize;
  KeyNode **oldTable = table;
  tableSize = max+1;
  table = new KeyNode*[tableSize];
  for(int i = 0; i < tableSize; i++)
    table[i] = nullptr;
  count = 0;

  KeyNode *cursor;
  for(int i = 0; i < oldTableSize; ++i) {
    cursor = oldTable[i];
    while(oldTable[i] != nullptr){
      insert(oldTable[i]->key);
      cursor = cursor->next;
      //cout << "deleting "<< oldTable[i]->key <<endl;
      delete oldTable[i];
      oldTable[i] = cursor;
    }
  }
  delete[] oldTable;
}



/*Su solución aquí******************/
unsigned int HashTab::hash(const vector<int> &key) {
  int count = 0;
  for (unsigned i=0; i< key.size(); i++){
    count += key[i];
  }
  return abs(count);
}
/***********************************/


/*Su solución aquí******************/
void HashTab::display_bucket(int i) {
  KeyNode* tmp = table[i];
  for (unsigned i=0; i< tmp->key.size(); i++){
    cout << tmp->key[i] << " -- ";
  }
  cout << endl;
}
/***********************************/


ostream& operator<<(ostream &os, vector<int> &v) {
  os << "(";
  for(int i : v)
    os << i << ",";
  os << '\b';
  os << ")";
}
