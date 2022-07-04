int solve(int i,int j, vector<int> &arr, vector<vector<int>> &dp, int N){
    if(i>=j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    int minval = INT_MAX,temp;
    for(int k=i;k<j;k++){
        temp = solve(i,k,arr,dp,N) + solve(k+1,j,arr,dp,N) + 
               arr[i-1] * arr[k] * arr[j];
        minval = min(minval,temp);
    }
    return dp[i][j] = minval;
}



int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here
    vector<vector<int>> dp(N,vector<int>(N,-1));
    return solve(1,N-1,arr,dp,N);
}