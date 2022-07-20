TreeNode<int>* solve(TreeNode<int>* root, int &k){
    if(root==NULL)return NULL;
    TreeNode<int>* right=solve(root->right,k);
    if(right!=NULL) return right;
    k--;
    if(k==0) return root;
    return solve(root->left,k);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
   TreeNode<int>* val = solve(root,k);
   return  val== NULL ? -1 : val->data;
}