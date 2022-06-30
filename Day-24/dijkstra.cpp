//https://www.codingninjas.com/codestudio/problems/920469
#include<bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
 // Write your code here. 
 //inserting reverse edges   
unordered_map<int,vector<pair<int,int>>> mp;
for(int i=0;i<edges;i++){
    mp[vec[i][0]].push_back({vec[i][1],vec[i][2]});
    mp[vec[i][1]].push_back({vec[i][0],vec[i][2]});
}    
    
 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
 vector<int> distance(vertices,INT_MAX);
 distance[source] = 0;
 pq.push({0,source});
 
 int dist,node;   
 while(!pq.empty()){
    dist = pq.top().first; node = pq.top().second; pq.pop();
    for(auto &p : mp[node]){
            if(distance[p.first] > p.second+dist){
                distance[p.first] = p.second+dist;
                pq.push({distance[p.first],p.first});
            }   
    } 
 } 
 return distance;   
}