#include<bits/stdc++.h>
long countWaysToMakeChange(int *coins, int n, int amount)
{
    //Write your code here
    vector<long> previous(amount+1,0),current(amount+1,0);
        
       for(int i=0;i<=amount;i++) 
           if(i%coins[0] == 0) previous[i] = 1;
        
     for(int ind=1; ind<n;ind++){
        for(int t=0;t<=amount;t++){
           long notTaken = previous[t];
            
            long taken = 0;
            if(coins[ind]<=t)
                taken = current[t-coins[ind]];
                
            current[t] = notTaken + taken;
        }
        previous = current;
    }
    
    return previous[amount];
        
}