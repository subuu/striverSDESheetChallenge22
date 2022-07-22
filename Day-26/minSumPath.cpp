int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
       int n = grid.size(), m = grid[0].size(),i,j;
        for(i = n-2; i>=0; i--) grid[i][m-1] += grid[i+1][m-1];
        for(i = m-2; i>=0; i--) grid[n-1][i] += grid[n-1][i+1];
        
        for(i=n-2;i>=0;i--){
            for(j=m-2;j>=0;j--){
                grid[i][j] += min(grid[i][j+1],grid[i+1][j]);
            }
        }
        
       return grid[0][0]; 
}