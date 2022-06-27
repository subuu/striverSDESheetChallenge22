#include<bits/stdc++.h>
void findTopsort(int node,vector<vector<int>> &neighbors,vector<bool> &visited ,stack<int> &st){
    visited[node] = true;
    for(auto &p : neighbors[node]){
       if(!visited[p])
            findTopsort(p,neighbors,visited,st); 
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>> neighbors(v);
    for(int i=0;i<e;i++){
        neighbors[edges[i][0]].push_back(edges[i][1]);
    }
    stack<int>st;
    vector<bool> visited(v,false);
    
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
            findTopsort(i,neighbors,visited,st);
    }
   vector<int> ans; int val;
   while(!st.empty()){
       val = st.top(); st.pop();
       ans.push_back(val);
   } 
   
    if(ans.size()!=v){
       for(int i=0;i<v;i++) 
        if(!visited[i])
            ans.push_back(i);
    }
    
    return ans;
}