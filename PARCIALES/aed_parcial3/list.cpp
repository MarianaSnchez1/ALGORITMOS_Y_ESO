#ifdef __LIST_HPP
template <typename T>
List<T>::List() {
  back = nullptr;
  front = nullptr;
  size = 0;
}

template <typename T>
List<T>::~List() {
  while(!empty()){
    pop_back();
  }
}

template <typename T>
bool List<T>::empty() {
  return size == 0;
}

/****Implemente estos métodos****/
template <typename T>
void List<T>::push_back(T v) {
  Cell<T> *tmp = new Cell<T>;
  tmp->val = v;
  if (back == nullptr){
    front = tmp;
    tmp->next = nullptr;
  }
  else{
    back->prev = tmp;
    tmp->next = back;
  }
  tmp->prev = nullptr;
  back = tmp;
  size++;
}

template <typename T>
void List<T>::push_front(T v) {
  Cell<T> *tmp = new Cell<T>;
  tmp->val = v;
  if (front == nullptr){
    back = tmp;
    tmp->prev = nullptr;
  }
  else{
    front->next = tmp;
    tmp->prev = front;
  }
  tmp->next = nullptr;
  front = tmp;
  size++;
}

template <typename T>
void List<T>::pop_back() {
  if (back == nullptr){
    std::cout << "cant remove empty list, pop_back" << std::endl;
    return;
  }
  Cell<T> *tmp;
  tmp = back;
  if (size == 1){
    delete tmp;
    front = nullptr;
    back = nullptr;
  } else{
    back = back->next;
    delete tmp;
    back->prev = nullptr;
  }
  size--;
}

template <typename T>
void List<T>::pop_front() {
  if (front == nullptr){
    std::cout << "cant remove empty list, pop_front" << std::endl;
    return;
  }
  Cell<T> *tmp;
  tmp = front;
  if (size == 1){
    delete tmp;
    front = nullptr;
    back = nullptr;
  }
  else{
    front = front->prev;
    front->next = nullptr;
    delete tmp;
  }
  size--;
}
/********************************/

template <typename T>
T List<T>::get_back() {
  return back->val;
}

template <typename T>
T List<T>::get_front() {
  return front->val;
}

template <typename T>
void List<T>::display() {
  Cell<T> *tmp = back;
  while(tmp != nullptr){
    std::cout << tmp->val << " ";
    tmp = tmp->next;
  }
  std::cout << "\n";
}
#endif
