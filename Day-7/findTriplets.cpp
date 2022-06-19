#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>nums, int n, int K) {
	// Write your code here.
        if(n < 2) return {};
        
        sort(nums.begin(),nums.end());
        
        int s,e,sum;
        vector<vector<int>> vec;
        vector<int> v;
        
        for(int i=0;i<n-2;i++)
        {   
            if(i > 0 and nums[i] == nums[i-1])
               continue;
            
            s = i+1; e = n-1,sum = K - nums[i];
            while(s < e)
            {   
                int val = nums[s] + nums[e];
                if(val == sum)
                {v.push_back(nums[i]);
                 v.push_back(nums[s]);
                 v.push_back(nums[e]);
                 vec.push_back(v); v.clear();e--;
                    while (s < e and nums[e] == nums[e + 1]) e--;
                }
                else if(val > sum) e--;
                else s++;
            }   
        }
        return vec;
}