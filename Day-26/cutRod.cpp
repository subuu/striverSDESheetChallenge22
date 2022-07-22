#include<bits/stdc++.h>
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<int> current(n+1,0);
    for(int i=0;i<=n;i++) current[i] = i*price[0];
    
    for(int i=1;i<n;i++){
        for(int j=0;j<=n;j++){
            int notincluded = 0 + current[j];
            int included = INT_MIN;
            int rodlen = i+1;
            if(rodlen<=j) included = price[i] + current[j-rodlen];
            
            current[j] = max(included,notincluded);
        }
    }
    return current[n];
}
