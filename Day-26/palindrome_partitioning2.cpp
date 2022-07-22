//https://www.codingninjas.com/codestudio/problems/873266
#include<bits/stdc++.h>
int palindromePartitioning(string str) {
    if(str.length() <= 1) return 0;
    else if(str.length() == 2) return str[0] == str[1] ? 0 :1;
    // Write your code here
    int n =  str.length();
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    
    //filling up the 2d boolean array
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g==0) dp[i][j] = true;
            else if(g==1) dp[i][j] = str[i] == str[j];
            else{
                if(str[i] == str[j] and dp[i+1][j-1])
                    dp[i][j] = true;
            }
        }
    }
//    This makes O(n^3)    
//     vector<vector<int>> cutarr(n,vector<int>(n,0));int minval;
//      for(int g=0;g<n;g++){
//         for(int i=0,j=g;j<n;i++,j++){
//             if(g==0) cutarr[i][j] = 0;
//             else if(g==1) cutarr[i][j] = str[i] == str[j] ? 0:1;
//             else{
//                 if(dp[i][j]) cutarr[i][j] = 0;
//                 else{
//                     minval = INT_MAX;
//                     for(int k=i;k<j;k++){
//                         if(cutarr[i][k] + cutarr[k+1][j] + 1 < minval)
//                             minval = cutarr[i][k] + cutarr[k+1][j] + 1;
//                     }
//                     cutarr[i][j] = minval;
//                 }
//             }
//         }
//     }
// return cutarr[0][n-1];
    
//This makes O(n^2)
    vector<int> cutarr(n,0);
    cutarr[1] = str[0]==str[1] ? 0 : 1;
    
    for(int j=2;j<n;j++){
        if(dp[0][j]) cutarr[j] = 0;
        else{
          int minval = INT_MAX;  
          for(int i=j;i>=1;i--){
            if(dp[i][j] and cutarr[i-1]+1<minval){
                  minval = cutarr[i-1]+1;
            } 
          }
          cutarr[j] = minval;  
        }
    }
    return cutarr[n-1];
}