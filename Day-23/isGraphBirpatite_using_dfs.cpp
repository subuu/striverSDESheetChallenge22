#include<bits/stdc++.h>
bool isCheckBipartite(int node,vector<vector<int>>& graph, int *color){
       for(auto &p : graph[node]){
           if(color[p] == -1){
                color[p] = 1-color[node];
                if(!isCheckBipartite(p,graph,color)) return false;
           }
           else if(color[p] == color[node]) return false;
       }
      return true; 
   } 
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
    int n = edges.size();
    vector<vector<int>> graph(n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(edges[i][j]==1) graph[i].push_back(j);
        }
    }
        int color[n];
        memset(color,-1,sizeof color);
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                color[i] = 1;
                if(!isCheckBipartite(i,graph,color)) return false;
            }
        }
        return true;
}