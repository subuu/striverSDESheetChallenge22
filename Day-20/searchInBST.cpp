bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(!root) return false;
    if(root->data == x) return true;
    else if(root->data > x) return searchInBST(root->left,x);
    else return searchInBST(root->right,x);
}