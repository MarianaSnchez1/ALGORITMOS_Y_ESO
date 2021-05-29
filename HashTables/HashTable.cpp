#ifdef _hash_table_hpp_


//___________________PRIVADO_________________

template <typename VT>
HashTable<VT>:: HashTable(){
  nBuckets = TABLE_SIZE;
  buckets = new Node<VT>*[nBuckets];
  load_factor = (float)count/(float)nBuckets;

  for (int i = 0; i < nBuckets; i++){
    buckets[i] = NULL;
  }

  count = 0;
}

template <typename VT>
HashTable<VT>:: ~HashTable(){
  clear();
  count = 0;
}

//___________________PUBLICO_________________

template <typename VT>
int HashTable<VT>:: size(){
  return count;
}

template <typename VT>
bool HashTable<VT>::empty(){
  if (count == 0){
    return true;
  }
  return false;
}

template <typename VT>
void HashTable<VT>::clear(){

  Node<VT> *recor;

  for(int i = 0; i < nBuckets; i++){
    recor = buckets[i];

    while(recor != nullptr){
      Node<VT> *borrar;
      borrar = recor;
      recor = recor->next;
      delete borrar;
    }
  }
}


template <typename VT>
float HashTable<VT>::load_factor_ret(){
  return (float)count/(float)nBuckets;
}


template <typename VT>
VT HashTable<VT>::get(string key){
  unsigned int hash = HashTable<VT>::hash(key);

  Node<VT> *nodo = search_bucket(hash, key);

  return nodo->value;
}

template <typename VT>
bool HashTable<VT>::search(string key){

  unsigned int hash = HashTable<VT>::hash(key);

  Node<VT> *nodo = search_bucket(hash, key);

  if (nodo == nullptr){
    return false;
  }
  return true;
}

template <typename VT>
bool HashTable<VT>::insert(string key, VT value){

  if (search(key) == true){
    Node<VT> * nodo = search_bucket(HashTable<VT>::hash(key) % TABLE_SIZE, key);
    nodo->value = value;
    return true;
  }
  else{
     unsigned int index = HashTable<VT>::hash(key)% TABLE_SIZE;
     Node<VT> *recor = buckets[index];

     Node<VT> *nuevo = new Node<VT>;
     nuevo->key = key;
     nuevo->value = value;

     if (buckets[index] == nullptr){
       buckets[index] = nuevo;
       nuevo->next = nullptr;
       count++;
       if (count/nBuckets > MAX_LOAD_FACTOR){
         cout << "SE PASO D:" << endl;
       }
       return false;
     }

     while(recor->next != nullptr){
       recor = recor->next;
     }
     recor->next = nuevo;
     nuevo->next = nullptr;
     count++;
     if (count/nBuckets > MAX_LOAD_FACTOR){
       cout << "SE PASO D:" << endl;
     }
  }
  return false;
}

template <typename VT>
void HashTable<VT>::remove(string key){

  unsigned int index = HashTable<VT>::hash(key) % TABLE_SIZE;

  if (search(key) == true){

     Node<VT> *borr = search_bucket(index, key);
     Node<VT> *recor = buckets[index];

     std::cout << "ola \n";

     if (recor->key == key){
       delete recor;
       buckets[index] = nullptr;
       count--;
     }

     else{
       while((recor->next)->key != key){
         recor = recor->next;
       }
       recor->next = borr->next;
       delete borr;

       count--;
     }
  }
  else{
    cout << "ErRoR: NO EXISTE UN NODO CON ESE KEY" << endl;
  }
}

template <typename VT>
void HashTable<VT>::display(){

  for(int i = 0; i < nBuckets; i++){
    Node<VT> *recor = buckets[i];
    std::cout << "Bucket[" << i <<"]: ";

    while (recor != nullptr){
      std::cout << recor->value << "-->";
      recor = recor->next;
    }
    std::cout << std::endl;
  }
}



#endif
