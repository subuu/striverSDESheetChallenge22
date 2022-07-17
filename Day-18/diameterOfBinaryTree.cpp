int dist(TreeNode<int> *root, int &d){
    if(!root) return 0;
    int l = dist(root->left,d);
    int r = dist(root->right,d);
    d = max(d,l+r);
    return 1+max(l,r);
}


int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    int d = 0;
    dist(root,d);
    return d;
}
