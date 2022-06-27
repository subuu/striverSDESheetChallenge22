#include<bits/stdc++.h>
bool isGraphBirpatite(vector<vector<int>> &edges) {
    // Write your code here.
    int n = edges.size();
    vector<vector<int>> neighbors(n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(edges[i][j]==1) neighbors[i].push_back(j);
        }
    }
   
        queue<int> q;  
        int color[n];
        memset(color,-1,sizeof color);
        color[0] = 1;
        q.push(0);
      
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto &p : neighbors[cur]){
                if(color[p] == -1){
                    color[p] = 1-color[cur];
                    q.push(p);
                }
                else if(color[p] == color[cur]) return false;   
            }
        }
    
        return true;
}#include<bits/stdc++.h>
bool isGraphBirpatite(vector<vector<int>> &edges) {
    // Write your code here.
    int n = edges.size();
    vector<vector<int>> neighbors(n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(edges[i][j]==1) neighbors[i].push_back(j);
        }
    }
   
        queue<int> q;  
        int color[n];
        memset(color,-1,sizeof color);
        color[0] = 1;
        q.push(0);
      
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto &p : neighbors[cur]){
                if(color[p] == -1){
                    color[p] = 1-color[cur];
                    q.push(p);
                }
                else if(color[p] == color[cur]) return false;   
            }
        }
    
        return true;
}