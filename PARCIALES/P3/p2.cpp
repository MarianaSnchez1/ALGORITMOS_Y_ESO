//P2
template <typename keyType>
bool bst<keyType>::check_if_bst (bstNode *root) const{
  if(root == nullptr) return true;
  if(root->left != nullptr && root->right != nullptr){
    if(root->left->key > root->key || root-> right->key < root->key) return false;
    check_if_bst (root->left);
    check_if_bst (root->right);
  }
  if(root->left != nullptr){
      if(root->left->key < root->key) return check_if_bst (root->left);
      return false;
  }
  if(root->right != nullptr){
      if(root-> right->key > root->key) return check_if_bst (root->right);
      return false;
  }
  return true;
}


template <typename keyType>
bool bst<keyType>::check_if_bst() const{
  return check_if_bst (tree);
}
