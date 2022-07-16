vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    if(!root)
          return {};
        
        vector<int> ans;
        queue<pair<TreeNode<int>*,int>> q;
        map<int,vector<int>> mp;
        q.push({root,0});
        
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)    
            {  
                TreeNode<int> *temp = q.front().first;
                int val = q.front().second;
                mp[val].push_back(temp->val);
                q.pop();
                    
                if(temp->left)    
                   q.push({temp->left,val-1});           
                if(temp->right)    
                   q.push({temp->right,val+1});
            }
        }
    
        for(auto p: mp){
            ans.push_back(p.second[0]);
        }
        return ans;
}