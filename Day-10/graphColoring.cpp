bool isValidTolaceColor(int node, vector<vector<int>> &mat, int m, int n, vector<int> &colors,int col){
    for(int i=0;i<n;i++){
        if(i != node and (mat[i][node] == 1 or mat[node][i] == 1) and colors[i] == col)
        return false;
    }
    return true;
}

bool solvegraph(int node, vector<vector<int>> &mat, int m, int n, vector<int> &colors){
    if(node == n) return true;
    
    for(int i=1;i<=m;i++){
        if(isValidTolaceColor(node,mat,m,n,colors,i)){
            colors[node] = i;
            if(solvegraph(node+1,mat,m,n,colors)) return true;
            colors[node] = 0;
        }   
    }
    return false; 
}

string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n = mat.size();
    vector<int>colors(n,0);
    return solvegraph(0,mat,m,n,colors) == true ? "YES" : "NO";
}