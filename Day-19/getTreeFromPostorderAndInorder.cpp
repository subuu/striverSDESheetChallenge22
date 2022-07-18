int findIndex(vector<int> &arr,int strt,int end,int value)
{
    for(int i=strt;i<=end;i++)
        if(arr[i] == value) return i;
 return -1;   
}

int postOrderIndex;
TreeNode<int> *createTree(vector<int> &postOrder,vector<int> &inOrder,int start,int end){
     
    if(start > end) return NULL;

    TreeNode<int> *node = new TreeNode<int>(postOrder[postOrderIndex--]);
    int rootIndex = findIndex(inOrder,start,end,node->data);
    
    node->right  = createTree(postOrder,inOrder,rootIndex+1,end);
    node->left = createTree(postOrder,inOrder,start,rootIndex-1);
 return node;
}
    
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
     int n = inOrder.size();
     postOrderIndex = n-1;
     return createTree(postOrder,inOrder,0,n-1);
}