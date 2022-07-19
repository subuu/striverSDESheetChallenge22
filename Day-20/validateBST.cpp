bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    if(!root || (!root->left and !root->right)) return true;
    queue<pair<BinaryTreeNode<int> *,pair<int,int>>> q;
    q.push({root,{INT_MIN,INT_MAX}});
    
    int mn,mx; BinaryTreeNode<int> * node;
    while(!q.empty()){
        node = q.front().first, mn = q.front().second.first;
        mx = q.front().second.second; q.pop();
        
        if(!node->left) {}
        else if(node->left->data > mn and node->left->data <= node->data)
            q.push({node->left,{mn, node->data}});
        else return false;
        
        if(!node->right) {}
        else if(node->right->data < mx and node->right->data >= node->data)
            q.push({node->right,{node->data,mx}});
        else return false;
    }
  return true;  
    
}