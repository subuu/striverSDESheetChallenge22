#include<bits/stdc++.h>
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    vector<int> previous(w+1,0);
    for(int i=weights[0];i<=w;i++) previous[i] = values[0];
    
    int notpicked,picked;
    for(int i=1;i<n;i++){
        for(int cap=w; cap>=0;cap--){
          notpicked = 0 + previous[cap];
          picked  = INT_MIN;
          if(weights[i] <= cap)
              picked = values[i] + previous[cap-weights[i]];
        
         previous[cap] = max(notpicked,picked);
      }
    }
  return previous[w];
}