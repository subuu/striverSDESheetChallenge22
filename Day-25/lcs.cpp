#include<bits/stdc++.h>
int lcs(string s, string t)
{
	//Write your code here
    int n = s.length(), m = t.length();
    vector<int> current(m+1,0), previous(m+1,0);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == t[j-1])
              current[j] = 1 + previous[j-1];
            else
              current[j] = max(previous[j], current[j-1]);  
       }
        previous = current;
    }
    
   return previous[m]; 
}