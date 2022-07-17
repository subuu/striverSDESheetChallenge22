int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
     if (root == NULL) return -1;
     else if(root->data == x || root->data == y) return root->data;
     
        int left = lowestCommonAncestor(root->left, x, y);
        int right = lowestCommonAncestor(root->right, x, y);

        if(left == -1) return right;
        else if(right == -1) return left;
        else return root->data;
}