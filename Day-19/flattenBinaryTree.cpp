TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) return NULL;
    TreeNode<int> * current  = root;
    while(current){
        if(current->left){
        TreeNode<int> * previous = current->left; 
        while(previous->right) previous = previous->right;   
        previous->right = current->right;
        current->right = current->left;    
        current->left = NULL;
        }
        current = current->right;
    }
    return root;
}