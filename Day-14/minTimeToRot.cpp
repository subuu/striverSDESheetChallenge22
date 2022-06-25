#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here.
    if(grid.empty()) return 0;
    queue<pair<int,int>> rotten; 
    int total_oranges = 0, counted_oranges=0,time=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] != 0) total_oranges++;
            if(grid[i][j] ==2) rotten.push({i,j});
        }
    }
    
    int dx[] = {0,0,1,-1},dy[] = {1,-1,0,0};
    while(!rotten.empty()){
      int k = rotten.size();
      counted_oranges += k;  
      while(k--){
          int x = rotten.front().first, y= rotten.front().second;
          rotten.pop();
          for(int i=0;i<4;i++){
              int x1 = x + dx[i], y1 = y+dy[i];
         if(x1 < 0 || y1<0 || x1 >= n || y>= m || grid[x1][y1] != 1) continue;
              grid[x1][y1] = 2;
              rotten.push({x1,y1});
          } 
      }  
      if(!rotten.empty()) time++;  
    }
    return total_oranges == counted_oranges ? time : -1;
}