bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here. 	
    if(!root1 and !root2) return true;
    if((!root1 and root2) or (!root2 and root1) or (root1->data != root2->data)) return false;
    
    return identicalTrees(root1->left, root2->left) and identicalTrees(root1->right, root2->right);
}