pair<int,int> solve(BinaryTreeNode<int>* root){
    if(!root) return {0,1};
    
    pair<int,int> pleft = solve(root->left);
    pair<int,int> pright = solve(root->right);
    
    if(!pleft.second or !pright.second or abs(pleft.first - pright.first)>1){
        return {1+max(pleft.first,pright.first),0};
    }
    else{
        return {1+max(pleft.first,pright.first),1};
    }
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    return solve(root).second;
}