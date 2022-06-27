void eraseIsland(int** grid, int x, int y,int m, int n){
        if(x<0 || y<0 || x==m || y==n|| grid[x][y] == 0)
              return;
        grid[x][y] = 0;
        eraseIsland(grid,x-1,y,m,n);
        eraseIsland(grid,x+1,y,m,n);
        eraseIsland(grid,x,y-1,m,n);
        eraseIsland(grid,x,y+1,m,n);
    
        eraseIsland(grid,x-1,y-1,m,n);
        eraseIsland(grid,x+1,y+1,m,n);
        eraseIsland(grid,x+1,y-1,m,n);
        eraseIsland(grid,x-1,y+1,m,n);
        
}

int getTotalIslands(int** grid, int m, int n)
{
   // Write your code here.
      int islands = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)
                { islands++; eraseIsland(grid,i,j,m,n);}
            }
        }   
       return  islands;
}
