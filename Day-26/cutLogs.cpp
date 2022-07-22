#include<bits/stdc++.h>
int solve(int n, int k, vector<vector<int>> &dp){
       if(dp[n][k] != -1) return dp[n][k];
       if (n == 1 || k == 1 || k == 0)
          return k;
        
        int minval = INT_MAX,temp;
        int l =1,r=k;
        while(l<=r){
            int x = (l+(r-l)/2);
            int temp1 = solve(n-1,x-1,dp);
            int temp2 = solve(n,k-x,dp);
            int temp3 = 1 + max(temp1,temp2);
            
            if(temp1 > temp2) r = x-1;
            else l = x+1;
            minval = min(minval,temp3);
        }
         return dp[n][k] = minval;
 }

int cutLogs(int k, int n)
{   //k->axes/eggs and n->floors/log stand
    // Write your code here.
       vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
      return solve(k,n,dp);
}
