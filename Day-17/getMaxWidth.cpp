int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) return 0;
    int ans = 0;
    queue<TreeNode<int> *> q;
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        ans = max(ans,size);
        while(size--){
            TreeNode<int> * node = q.front(); q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return ans; 
}