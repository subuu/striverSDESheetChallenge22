bool checksymmetry(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2){
if(!root1 and !root2) return true;   
if((!root1 and root2) or (root1 and !root2) or (root1->data != root2->data))
    return false;

  return checksymmetry(root1->left,root2->right) and 
         checksymmetry(root1->right,root2->left);   
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here.
    if(!root) return true;
    else return checksymmetry(root->left,root->right);
}