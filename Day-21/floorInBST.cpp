void solve(TreeNode<int> * root, int X,int &val){
    if(!root) return;
    if(root->val == X) val = root->val;
    else if(root->val > X) solve(root->left,X,val);
    else{
        val = root->val;
        solve(root->right,X,val);
    }
}

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int val = -1;
    solve(root,X,val);
    return val;
}