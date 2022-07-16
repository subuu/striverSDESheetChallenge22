bool findPath(TreeNode* root, int B,  vector<int> &ans){
    if(!root) return false;
    if(root->val == B){
        ans.push_back(root->val); return true;
    }
    
    ans.push_back(root->val);
    if(root->left and findPath(root->left,B,ans)) return true;
    if(root->right and findPath(root->right,B,ans)) return true;
    ans.pop_back(); 
  return false;  
}



vector<int> Solution::solve(TreeNode* A, int B) {
    if(!A) return {};
    vector<int> ans;
    findPath(A,B,ans);
    return ans;
}