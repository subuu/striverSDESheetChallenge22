#include<bits/stdc++.h>
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> distance(n+1,1000000000);
    distance[src] = 0;
    for(int i=1;i<=n-1;i++){
     for(auto &p : edges){
      if(distance[p[0]]!=1000000000 and distance[p[0]] + p[2] < distance[p[1]])
                distance[p[1]] = distance[p[0]] + p[2];
        }
    } 
    return distance[dest]; 
}