//https://www.codingninjas.com/codestudio/problems/985311
#include<bits/stdc++.h>
void rundfs(int node, stack<int> &st, vector<bool> &visited, vector<vector<int>> &neighbours) {
    visited[node] = true; 
    for(auto &p: neighbours[node]) {
        if(!visited[p]) rundfs(p, st, visited,neighbours);
    }
    st.push(node); 
}

void runrevDfs(int node, vector<bool> &visited, vector<vector<int>> &neighbours_transpose,vector<int> &sccComponent) {
    sccComponent.push_back(node); 
    visited[node] = true; 
    for(auto &p: neighbours_transpose[node]) {
        if(!visited[p]) {
            runrevDfs(p, visited, neighbours_transpose,sccComponent); 
        }
    }
}


vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> neighbours(n);
    for(int i=0;i<edges.size();i++) 
        neighbours[edges[i][0]].push_back(edges[i][1]);
    
    vector<bool> visited(n,false);
    vector<vector<int>> neighbours_transpose(n); 
    stack<int> st;
  
    for(int i = 0;i<n;i++) {
        if(!visited[i]) rundfs(i,st,visited,neighbours);   
    } 
   
    for(int i = 0;i<n;i++) {
        visited[i] = false; 
        for(auto &p: neighbours[i]) {
            neighbours_transpose[p].push_back(i); 
        }
    }
    
    while(!st.empty()) {
        int node = st.top();
        st.pop(); 
        if(!visited[node]) {
            vector<int> sccComponent;
            runrevDfs(node, visited, neighbours_transpose,sccComponent);
            ans.push_back(sccComponent); 
        }
    }
   
   return ans; 
}