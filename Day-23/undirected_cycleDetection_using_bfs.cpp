#include<bits/stdc++.h>
bool isCyclePresent(int node, vector<vector<int>>&neighbours,vector<bool> &visited){
  queue<pair<int,int>> q;
  visited[node] = true;
  q.push({node,-1}); 
  
  while(!q.empty()){
     int curr = q.front().first; int par = q.front().second; 
     q.pop(); 
     for(auto &p : neighbours[curr]){
         if(!visited[p]){
           visited[p] = true;
           q.push({p,curr});  
        }
        else if(p != par) return true; 
     }   
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
            if(isCyclePresent(i,neighbours,visited))
                        {ans =true; break;}
        }
    }
    
    return ans == true ? "Yes" : "No";
}
