vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
         
        if(!root)
          return {};
        
        vector<int> ans;
        queue<TreeNode<int>*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            
            for(int i=0;i<n;i++)    
            {  
                TreeNode<int> *temp = q.front();
                q.pop();
                
                if(i==0)
                   ans.push_back(temp->data);
                    
                if(temp->left)    
                   q.push(temp->left);
                
                if(temp->right)    
                   q.push(temp->right);
            }
        }
        
        return ans;
}