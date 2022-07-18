int findIndex(vector<int> &arr,int strt,int end,int value)
{
    for(int i=strt;i<=end;i++)
        if(arr[i] == value)  return i;
 return -1;   
}

TreeNode<int> *createTree(vector<int> &preOrderarr,vector<int> &inOrderarr,int start,int end, int &preOrderIndex){
     
    if(start > end ) return NULL;

    TreeNode<int> *node = new TreeNode<int>(preOrderarr[preOrderIndex++]);
    int rootIndex = findIndex(inOrderarr,start,end,node->data);
   
    node->left = 
        createTree(preOrderarr,inOrderarr,start,rootIndex-1,preOrderIndex);
    node->right  =                
        createTree(preOrderarr,inOrderarr,rootIndex+1,end,preOrderIndex);

 return node;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
        int n = inorder.size();
        int preOrderIndex=0;
        return createTree(preorder,inorder,0,n-1,preOrderIndex);
}