void Traversal(TreeNode* root,vector<int> &v)
    {
        if(root == NULL)
            return;
        
        Traversal(root->left,v);
        v.push_back(root->data);
        Traversal(root->right,v);  
    }
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
      vector<int> v;
       Traversal(root,v);
       return v;
}