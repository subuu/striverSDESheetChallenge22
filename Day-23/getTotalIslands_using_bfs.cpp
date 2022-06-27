#include<bits/stdc++.h>
int getTotalIslands(int** grid, int m, int n)
{
   // Write your code here.
      int islands = 0;
       vector<int> dx = {0,0,1,-1,1,1,-1,-1};
       vector<int> dy = {1,-1,0,-0,1,-1,1,-1};
    
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){  
                 islands++; 
                 queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                       int r = q.front().first, c= q.front().second; q.pop(); 
                       for(int k=0;k<8;k++){
                           int x1 = r + dx[k], y1 = c + dy[k];
                           if(x1 >=0 and x1<m and y1 >=0 and y1<n 
                              and grid[x1][y1] == 1){
                               q.push({x1,y1});
                               grid[x1][y1] = 0;
                           }
                       } 
                    }
                }
            }
        }   
       return  islands;
}
