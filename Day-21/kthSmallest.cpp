void kvalBst(TreeNode<int> *root, int k,vector<int> &v)
{
  if(!root || v.size()==k) return;
 
  kvalBst(root->left,k,v); 
  v.push_back(root->data);
  kvalBst(root->right,k,v);
}

int kthSmallest(TreeNode<int> *root, int k)
{
   //Write the code here.
   vector<int> v;
   kvalBst(root,k,v);
   return v[k-1]; 
}