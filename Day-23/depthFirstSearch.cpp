#include<bits/stdc++.h>
void dfs(int currNode,int V, vector<vector<int>> neighbors,vector<int> &path,vector<int> &visited)
    {
        path.push_back(currNode);
        visited[currNode] = 1;
        
        for(auto &p : neighbors[currNode]){
            if(!visited[p])
                dfs(p,V,neighbors,path,visited);
        }
    }

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> neighbors(V);
    for(int i=0;i<E;i++){
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }
    
    vector<vector<int>> dfsorder;
    vector<int> visited(V);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                    vector<int> path;
                    dfs(i,V,neighbors,path,visited);
                    dfsorder.push_back(path);
            } 
        }
   return dfsorder;
}