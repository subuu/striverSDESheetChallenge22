void solve(BinaryTreeNode<int> * root, int X,int &val){
    if(!root) return;
    if(root->data == X) val = root->data;
    else if(root->data < X) solve(root->right,X,val);
    else{
        val = root->data;
        solve(root->left,X,val);
    }
}

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int val = -1;
    solve(node,x,val);
    return val;
}