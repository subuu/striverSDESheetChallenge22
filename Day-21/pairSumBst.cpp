bool ispairSumBst(BinaryTreeNode<int> *root, int k,unordered_set<int> &s)
{
  if(!root) return false;
  if(s.find(k-root->data) != s.end()) return true;
  else s.insert(root->data);
    
  return ispairSumBst(root->left, k, s) || ispairSumBst(root->right, k, s);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    unordered_set<int> s;
    return ispairSumBst(root, k, s);
}