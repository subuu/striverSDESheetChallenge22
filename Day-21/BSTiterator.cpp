class BSTiterator
{
  public:    
     vector<int> node;
    TreeNode<int>* head;
    int size,curr;
    
    void inorder(TreeNode<int>* root)
    {
        if(!root)
          return;
        
        inorder(root->left);
        node.push_back(root->data);
        inorder(root->right);
    }
    
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        head = root;
        inorder(root);
        size = node.size();curr=0;
    }

    int next()
    {
        // write your code here
         return node[curr++];
    }

    bool hasNext()
    {
        // write your code here
        if(curr < size)
            return true;
        else
            return false;
    }
};