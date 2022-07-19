TreeNode<int>* createTree(vector<int> &arr, int n, int s, int e){
    if(s>e) return NULL;
    
    int mid = (s+e)/2;
    TreeNode<int>*  node = new TreeNode<int>(arr[mid]);
    node->left = createTree(arr,n,s,mid-1);
    node->right = createTree(arr,n,mid+1,e);
   return node; 
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return createTree(arr,n,0,n-1);
}