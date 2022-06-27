#include<bits/stdc++.h>
bool isCyclePresent(int node,vector<vector<int>> &neighbors,bool *visited, bool *neighborvisited){
   visited[node] = neighborvisited[node] = true; 
   for(auto &p : neighbors[node]) 
   {
       if(!visited[p]){
            if(isCyclePresent(p,neighbors,visited,neighborvisited))
                  return true;
        }
       else if(neighborvisited[p]) return true;  
   } 
    
   neighborvisited[node] = false;
   return false; 
}

int detectCycleInDirectedGraph(int n, vector <pair<int, int>> & edges) {
  // Write your code here.
   vector<vector<int>> neighbors(n+1);
    for(int i=0;i<edges.size();i++){
        neighbors[edges[i].first].push_back(edges[i].second);
    } 
    
    bool visited[n+1],neighborvisited[n+1];
    memset(visited,false,sizeof(visited));
    memset(neighborvisited,false,sizeof(neighborvisited));
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(isCyclePresent(i,neighbors,visited,neighborvisited))
                  return 1;
        }
    }
  return 0; 
}