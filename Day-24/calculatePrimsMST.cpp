#include<bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
 unordered_map<int,vector<pair<int,int>>> neighbours;   
 for(int i=0;i<g.size();i++)
 {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        
        neighbours[u].push_back(make_pair(v, w));
        neighbours[v].push_back(make_pair(u, w));
 }
    
vector<int> key(n+1,INT_MAX),parent(n+1,-1); vector<bool> inMST(n+1,false);
priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
 key[1] = 0; pq.push({0,1}); int node,adjnode,wt;  
 while(!pq.empty()){
     node = pq.top().second; pq.pop();
     inMST[node]=true;  // selecting the current node in MST
     for(auto &p : neighbours[node]){
        adjnode =  p.first; wt = p.second;
        if(!inMST[adjnode] and wt< key[adjnode]){
            key[adjnode] = wt;
            parent[adjnode] = node;
            pq.push({wt,adjnode});
        } 
     }
 }   
  
    
 g.clear(); pair<pair<int,int>,int> pr; 
 for(int i=2;i<=n;i++){
     pr.first.first = parent[i];
     pr.first.second = i;
     pr.second = key[i];
     g.push_back(pr);
 }   
  return g;   
}
