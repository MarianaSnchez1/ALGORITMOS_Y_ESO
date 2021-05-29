#ifdef _DUP_BST_HPP

/*__________PRIVATE__________*/
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

template <typename T>
void BST<T>::display_node(BSTNode<T> *node, int count){
  
}

/**/
/*
 *
 *
 *
 * Your
 * implementations
 * here
 *
 *
 *
 */
/**/

#endif
