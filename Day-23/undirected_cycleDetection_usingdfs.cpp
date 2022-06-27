#include<bits/stdc++.h>
bool isCyclePresent(int node,int parent,vector<vector<int>>&neighbours,vector<bool> &visited){
   visited[node]  = true; 
  for(auto &p : neighbours[node])  
  {
      if(!visited[p]){ 
         if(isCyclePresent(p,node,neighbours,visited)) return true;
      }
      else if(p != parent) return true;
  }
  return false;  
}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    if(edges.empty() or m == 0) return "No";
    vector<vector<int>> neighbours(n+1);
    for(int i=0;i<m;i++){
        neighbours[edges[i][0]].push_back(edges[i][1]);
        neighbours[edges[i][1]].push_back(edges[i][0]);
    }
   
   
    bool ans = false;
    vector<bool> visited(n+1,false);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(isCyclePresent(i,-1,neighbours,visited))
                        {ans =true; break;}
        }
    }
    
    return ans == true ? "Yes" : "No";
}
