void preorder(TreeNode* root, vector<int> &v ){
        
        if(root == NULL)
            return;
        
        v.push_back(root->data);
        preorder(root->left,v);
        preorder(root->right,v);  
    }
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
     vector <int> vec;
       preorder(root,vec);
        return vec;
}