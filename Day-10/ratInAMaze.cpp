vector<int> dx = {0,0,1,-1};
 vector<int> dy = {1,-1,0,0}; 

void solve(int x,int y,vector<vector<int>> &maze, int n,vector<vector<int>> &ans, vector<vector<bool>> &visited,vector<int> &path){
  
    if(x == n-1 and y == n-1) {
        ans.push_back(path); return ;}
    int xnew,ynew;
    for(int i=0;i<4;i++){
        xnew = x + dx[i]; ynew = y + dy[i];
        if(xnew>=0 and ynew >= 0 and xnew <n and ynew < n and maze[xnew][ynew] == 1 and visited[xnew][ynew] == false){
            visited[xnew][ynew] = true;
            path[xnew*n + ynew] = 1;
            solve(xnew,ynew,maze,n,ans,visited,path);
            visited[xnew][ynew] = false;
            path[xnew*n + ynew] = 0;
        }
    } 
}

vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n){
  // Write your code here.
  vector<vector<int>> ans;
  if(maze.empty() || maze[0][0] == 0 || maze[n-1] [n-1] == 0) return ans;  
  vector<vector<bool>> visited(n, vector<bool>(n,false));
  vector<int> path(n*n,0);  
  path[0] = 1;
  visited[0][0] = true;  
  solve(0,0,maze,n,ans,visited,path);   
  return ans;      
}