void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(!root) return;
    int val =0;
    val += root->left != NULL ? root->left->data : 0;
    val += root->right != NULL ? root->right->data : 0;
    
    if(val < root->data) {
      if(root->left) root->left->data = root->data;
      else if(root->right) root->right->data = root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    val=0;
    val += root->left != NULL ? root->left->data : 0;
    val += root->right != NULL ? root->right->data : 0;
    if(root->left || root->right) root->data = val;
}  