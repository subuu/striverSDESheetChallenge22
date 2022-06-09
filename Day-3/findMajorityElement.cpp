#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	// Write your code here.
    if(n == 0) return 0;
    int count = 0; int candidate = -1;
    unordered_map<int,int> mp;
        for (int num = 0; num < n;num++) {
           mp[arr[num]]++; 
        }
        
       for(auto p : mp)
           if( p.second > n/2)
           { candidate = p.first; break;}
        return candidate;
}