vector<int> bottomView(BinaryTreeNode<int> * root){
        if(!root)
          return {};
        
        vector<int> ans;
        queue<pair<BinaryTreeNode<int>*,int>> q;
        map<int,vector<int>> mp;
        q.push({root,0});
        
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)    
            {  
                BinaryTreeNode<int> *temp = q.front().first;
                int val = q.front().second;
                mp[val].push_back(temp->data);
                q.pop();
                    
                if(temp->left)    
                   q.push({temp->left,val-1});           
                if(temp->right)    
                   q.push({temp->right,val+1});
            }
        }
    
        for(auto p: mp){
            ans.push_back(p.second[p.second.size()-1]);
        }
        return ans;
}
