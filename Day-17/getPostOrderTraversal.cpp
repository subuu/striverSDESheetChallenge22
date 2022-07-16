void Traversal(TreeNode* root,vector<int> &v)
    {
        if(root == NULL)
            return;
        
        Traversal(root->left,v);
        Traversal(root->right,v);
        v.push_back(root->data);
          
    }
vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
      vector<int> v;
       Traversal(root,v);
        return v;
}