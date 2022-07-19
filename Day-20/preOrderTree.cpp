int findIndex(vector<int> &arr,int strt,int end,int value)
{
    if(strt<=end){
        int mid = (strt+end)/2;
        if(arr[mid] == value) return mid;
        else if(arr[mid] > value) return findIndex(arr,strt,mid-1,value); 
        else return findIndex(arr,mid+1,end,value);
    }
 return -1;   
}

int preOrderIndex;
TreeNode<int> *createTree(vector<int> &preOrder,vector<int> &inOrder,int start,int end){
     
    if(start > end) return NULL;

    TreeNode<int> *node = new TreeNode<int>(preOrder[preOrderIndex++]);
    int rootIndex = findIndex(inOrder,start,end,node->data);
   
    node->left = createTree(preOrder,inOrder,start,rootIndex-1);
    node->right  = createTree(preOrder,inOrder,rootIndex+1,end);   
 return node;
}
    
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    vector<int> inOrder= preOrder;
    preOrderIndex = 0;
    sort(inOrder.begin(),inOrder.end());
    return createTree(preOrder,inOrder,0,preOrder.size()-1);
}