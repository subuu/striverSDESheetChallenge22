vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    if(!root) return {};
    
    queue<BinaryTreeNode<int>*> q;
    vector<int> ans;
    q.push(root);
    
    int size=0;
    while(!q.empty()){
        size = q.size();
        while(size >0){
        BinaryTreeNode<int> *temp = q.front();
        q.pop(); size--;
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);    
        ans.push_back(temp->val); 
        }
    }
    return ans;
}