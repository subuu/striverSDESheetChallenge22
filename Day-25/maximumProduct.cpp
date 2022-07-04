#include<bits/stdc++.h>
int maximumProduct(vector<int> &nums, int n)
{
	// Write your code here
        int maxprod = nums[0], minprod = nums[0],ans=nums[0],temp=0;
        
        for(int i=1;i<n;i++){
            temp = max({nums[i], maxprod * nums[i], minprod * nums[i]});
            minprod = min({nums[i], maxprod * nums[i], minprod * nums[i]});
            maxprod = temp;
            
            ans = max(ans,maxprod);
        }
        
       return ans; 
}


