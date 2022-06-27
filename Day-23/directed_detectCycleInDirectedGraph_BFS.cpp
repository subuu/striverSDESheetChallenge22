#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector <pair<int, int>> & edges) {
  // Write your code here.
   vector<vector<int>> neighbors(n+1);
    for(int i=0;i<edges.size();i++){
        neighbors[edges[i].first].push_back(edges[i].second);
    } 
    
    vector<int> indegree(n+1,0);
        for(int i=1;i<=n;i++){
            for(auto &p : neighbors[i])
               indegree[p]++;
        }
        
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(indegree[i] == 0)
              q.push(i);
        }
        int cnt = 0;
        
        vector<int> ans;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            cnt++;
            
            for(auto &p : neighbors[cur]){
                if(--indegree[p] == 0)
                     q.push(p);
            }
        }
        
        return cnt==n ? false : true;
}