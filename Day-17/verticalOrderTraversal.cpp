
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    if(!root) return {};
    vector<int> ans;
    queue<pair<TreeNode<int> *,pair<int,int>>> q;
    q.push({root,{0,0}});
    map<int,map<int,vector<int>>> mp;
    
    while(!q.empty()){
        auto p = q.front().first;
        int x= q.front().second.first, y = q.front().second.second;
        q.pop();
        mp[x][y].push_back(p->data);
        if(p->left) q.push({p->left,{x-1,y+1}});
        if(p->right) q.push({p->right,{x+1,y+1}});
    }
    
    for(auto p : mp){
        for(auto k : p.second){
            for(auto z : k.second){
                ans.push_back(z);
            }
        }  
    }
    return ans; 
}