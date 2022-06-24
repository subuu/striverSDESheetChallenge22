    int num;
    vector<vector<int>> board;
    vector<vector<int>> ans;
    
    bool isValidToPlace(int i, int j){
        for(int k=0;k<num;k++){
            if(board[i][k] || board[k][j])
                return false;
        }
        
        int x = i,y = j;
        while(x >= 0 and y <num){
            if(board[x--][y++])
               return false;
        }
        
        x = i,y = j;
        while(x >= 0 and y>= 0){
            if(board[x--][y--])
               return false;
        }
        
        return true;
    }
    
    bool NQueen(int i){
        //base case
        if(i==num){
            vector<int> v; 
            for(int x=0;x<num;x++){
                for(int y=0;y<num;y++)
                    v.push_back(board[x][y]);
            }
            ans.push_back(v);
            return false;
        }
        
        for(int j = 0; j< num;j++){
            if(isValidToPlace(i,j)){
                board[i][j] = 1;
                bool isAllQueenPlaced = NQueen(i+1);
                if(isAllQueenPlaced) return true;
                board[i][j] = 0;
            }  
        }
        return false;
    }
    
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
        num = n;
        board.resize(n,vector<int>(n,0));
        NQueen(0);
        return ans;  
}