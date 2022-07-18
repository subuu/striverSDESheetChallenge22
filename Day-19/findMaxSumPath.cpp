long long int solve(TreeNode <int>* root, long long int &maxval, int &l) {
  if (root == NULL) return 0;
  if(root->left == NULL and root->right == NULL) l++;
 long long int leftMaxPath = solve(root -> left, maxval,l) ;
 leftMaxPath = 0 > leftMaxPath ? 0 : leftMaxPath;
 long long int rightMaxPath = solve(root -> right, maxval,l);
   rightMaxPath = 0 > rightMaxPath ? 0 : rightMaxPath;  
 long long int val = (leftMaxPath + rightMaxPath + root->val);   
  maxval = maxval > val ? maxval:val;
  return max(leftMaxPath, rightMaxPath) + root->val;

}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
       if(!root) return -1;
       long long int maxval = INT_MIN;
       int l=0;
        solve(root,maxval,l);
        return l==1 ? -1 :maxval;
}