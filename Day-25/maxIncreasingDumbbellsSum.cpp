#include<bits/stdc++.h>
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here
       vector<int> dp(n);
       dp = rack;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++)
                if(rack[i] > rack[j] and dp[i] < dp[j] + rack[i])
                    dp[i] = dp[j] + rack[i];
        }
     
       return *max_element(dp.begin(),dp.end()); 
}