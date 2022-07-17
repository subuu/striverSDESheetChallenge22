vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    if(!root) return {};
    vector<int> ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    bool flag = true;
    int l;
   while(!q.empty()){
       int size = q.size();
       if(!flag) l = ans.size();
       
       while(size--){
       auto p = q.front(); q.pop();
       ans.push_back(p->data);
       if(p->left) q.push(p->left);
       if(p->right) q.push(p->right);}
       
       if(!flag) reverse(ans.begin()+l,ans.end());
       flag = flag == true ? false : true;
   }
    return ans;
}