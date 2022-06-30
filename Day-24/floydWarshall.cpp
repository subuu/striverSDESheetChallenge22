//https://www.codingninjas.com/codestudio/problems/2041979
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<vector<int>> graph(n+1,vector<int>(n+1,1000000000));
    for(int i=1;i<=n;i++)
           graph[i][i] = 0;
    for(int i=0;i<m;i++){
        graph[edges[i][0]][edges[i][1]] = edges[i][2];
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
           for(int j=1;j<=n;j++){
             if(graph[i][k] != 1000000000 and graph[k][j] != 1000000000 
                and (graph[i][j] > graph[i][k] + graph[k][j]))
               graph[i][j] = graph[i][k] + graph[k][j];      
          }
       }
    }
    
   return graph[src][dest]; 
}