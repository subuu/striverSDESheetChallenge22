#include<bits/stdc++.h>
int editDistance(string str1, string str2)
{
    //write you code here
     int n= str1.size(), m= str2.size();
      vector<int> previous(m+1,0),current(m+1,0);
        
      for(int j=0;j<=m;j++) previous[j] = j;
        
      for(int i=1;i<=n;i++){
        current[0] = i;  
          for(int j=1;j<=m;j++){
              if(str1[i-1] == str2[j-1])
                  current[j] = previous[j-1];
              else
                  current[j] = 1 + min({previous[j-1],previous[j],current[j-1]});
          }
          previous = current;
      }  
        
       return previous[m]; 
}