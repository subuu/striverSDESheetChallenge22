void inorder(BinaryTreeNode<int> *root, vector<int> &in){
    if(!root) return;
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

void postorder(BinaryTreeNode<int> *root, vector<int> &post){
    if(!root) return;
    postorder(root->left,post);
    postorder(root->right,post);
    post.push_back(root->data);
}

void preorder(BinaryTreeNode<int> *root, vector<int> &pre){
    if(!root) return;
    pre.push_back(root->data); 
    preorder(root->left,pre); 
    preorder(root->right,pre);  
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> v;
    inorder(root,v);
    ans.push_back(v);
    
    vector<int> v1;
    preorder(root,v1);
    ans.push_back(v1);
    
    vector<int> v2;
    postorder(root,v2);
    ans.push_back(v2);
    
    return ans;
}