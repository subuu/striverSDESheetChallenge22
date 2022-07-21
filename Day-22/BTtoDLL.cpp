void solve(BinaryTreeNode<int>* root,vector<BinaryTreeNode<int>*> &v){
    if(!root) return;
    solve(root->left,v);
    v.push_back(root);
    solve(root->right,v);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    vector<BinaryTreeNode<int>*> v;
    solve(root,v);
    v[0]->left = NULL;
    v[0]->right = v[1];
    for(int i=1;i<v.size()-1;i++){
        v[i]->left = v[i-1];     
        v[i]->right = v[i+1];
    }
    v[v.size()-1]->left =  v[v.size()-2];
    v[v.size()-1]->right = NULL;
  return v[0];  
}