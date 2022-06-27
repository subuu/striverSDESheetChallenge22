#include<bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>> neighbors(v);
    for(int i=0;i<e;i++){
        neighbors[edges[i][0]].push_back(edges[i][1]);
    }
    
     vector<int> indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto &p : neighbors[i])
               indegree[p]++;
        }
        
        queue<int> q;
        for(int i=0;i<v;i++){
            if(indegree[i] == 0)
              q.push(i);
        }    
        
        vector<int> ans;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            ans.push_back(cur);
            
            for(auto &p : neighbors[cur]){
                if(--indegree[p] == 0)
                     q.push(p);
            }
        }
        
        return ans;  
}