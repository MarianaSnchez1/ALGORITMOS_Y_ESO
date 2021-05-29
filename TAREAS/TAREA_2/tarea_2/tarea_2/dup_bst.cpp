#ifdef _DUP_BST_HPP
#define _DUP_BST_HPP
using namespace std;

template <typename T>
void BST<T>::destroy_recursive(BSTNode<T> *node) {
  if(node != nullptr){
    destroy_recursive(node->left);
    destroy_recursive(node->right);
    delete node;
  }
}

template <typename T>
BSTNode<T>* BST<T>::minimum(BSTNode<T> *node) {
  while(node->left != nullptr)
    node = node->left;
  return node;
}

template <typename T>
BSTNode<T>* BST<T>::maximum(BSTNode<T> *node) {
  while(node->right != nullptr)
    node = node->right;
  return node;
}

template <typename T>
BSTNode<T>* BST<T>::predecessor(BSTNode<T> *node) {
  if(node->left != nullptr)
    return maximum(node->left);
  else{
    BSTNode<T>* p = node->parent;
    while(p != nullptr && node == p->left){
      node = p;
      p = node->parent;
    }
    return p;
  }
}

template <typename T>
BSTNode<T>* BST<T>::successor(BSTNode<T> *node) {
  if(node->right != nullptr)
    return minimum(node->right);
  else{
    BSTNode<T>* p = node->parent;
    while(p != nullptr && node == p->right){
      node = p;
      p = node->parent;
    }
    return p;
  }
}

//--------------- Private ---------------//

//Display
template <typename T>
void BST<T>::display_node(BSTNode<T> *node, int count) {
  if(node != nullptr){
    count++;
    display_node(node->left, count);
    cout << "(" << node->key <<", "<< node->reps << ")" << " ";
    display_node(node->right, count);
  }
}

//Insert
template <typename T>
void BST<T>::insert_node(BSTNode<T>* &node, BSTNode<T>* p, T k){
  if(node == nullptr){
    node = new BSTNode<T>;
    node->key = k;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = p;
    node->reps = 1;
  } else{
    if(k == node->key)
      (node->reps)++;
    else if(k < node->key)
      return insert_node(node->left, node,k);
    else
      return insert_node(node->right, node,k);
  }
}

//Find
template <typename T>
BSTNode<T>* BST<T>::find_node(BSTNode<T> *node, T k){
  if(node == nullptr)
    return nullptr;
  else if(k == node->key)
    return node;
  else if(k < node->key)
    return find_node(node->left, k);
  else
    return find_node(node->right,k);
}

//Remove
template<typename T>
BSTNode<T>* BST<T>::remove_node( BSTNode<T> * &node , T k){
  if (node == nullptr)
    return nullptr;
  if (k > node->key)
    remove_node(node->right,k);
  else if(k < node->key)
    remove_node(node->left,k);
  else if (node->reps>1){
    node->reps -= 1;
    return node;
  } else if (node->left==nullptr){
    BSTNode<T> * tmp = node;
    node=node->right;
    delete tmp;
  } else if (node->right==nullptr){
    BSTNode<T>* tmp = node;
    node = node->left;
    delete tmp;
  } else if(node->left != nullptr && node->right != nullptr){
    node->key = minimum(node->right)->key;
    remove_node(node->right, node->key);
  }
  return nullptr;
}

//Capacity recursive
template <typename T>
int BST<T>::capacity_recursive(BSTNode<T> *node, int &count){
  if(node != nullptr){
    capacity_recursive(node->left, count);
    count += node->reps;
    capacity_recursive(node->right,count);
  }
  return count;
}


//--------------- Public ---------------//

template <typename T>
void BST<T>::display(){
  if(root != nullptr)
    display_node(root, root->reps);
  cout << endl;
}

template <typename T>
void BST<T>::insert(T k){
  return insert_node(root, nullptr, k);
}

template <typename T>
BSTNode<T>* BST<T>::find(T k){
  return find_node(root, k);
}

template <typename T>
BSTNode<T>* BST<T>::remove(T k){
  return remove_node(root,k);
}

template <typename T>
int BST<T>::capacity(){
  int count = 0;
  return capacity_recursive(root,count);
}

#endif
