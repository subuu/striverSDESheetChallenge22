#include<bits/stdc++.h>
vector<int> BFS(int V, vector<pair<int, int>> edges)
{
    // Write your code here
       vector<vector<int>> neighbors(V);
    for(int i=0;i<edges.size();i++){
        neighbors[edges[i].first].push_back(edges[i].second);
        neighbors[edges[i].second].push_back(edges[i].first);
    }
    
    for(int i=0;i<neighbors.size();i++)
        sort(neighbors[i].begin(),neighbors[i].end());
    
        vector<int> bfsorder;
        vector<bool> visited(V,false);
        queue<int> q;
        
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
     
            int curr = q.front(); q.pop();
            bfsorder.push_back(curr);
       
            for(auto &p : neighbors[curr]){
                if(!visited[p]){
                    q.push(p);
                    visited[p] = true;
                }
            }
            
        }
        
        if(bfsorder.size() != V){
            for(int i=0;i<V;i++){
                if(!visited[i])
                    bfsorder.push_back(i);
            }
        }
    
        return bfsorder;
}