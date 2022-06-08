#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
     int len = prices.size();
        int minVal = prices[0];
        int maxVal = 0;
        
        for(int i=1;i<len;i++)
        {
            minVal = min(minVal,prices[i]);
            maxVal = max(maxVal,prices[i]-minVal);           
        }
        
       return maxVal; 
}