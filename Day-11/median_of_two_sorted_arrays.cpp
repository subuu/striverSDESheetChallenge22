#include<bits/stdc++.h> 
double solve(vector<int>& nums1, vector<int>& nums2, int m, int n){
        if(m > n) return solve(nums2,nums1,n,m);
        
        int low=0,high=m,part1,part2,left1,left2,right1,right2;
        int median = (m+n+1)/2;
        
        while(low <= high){
            part1 = low + (high-low)/2;
            part2 = median - part1;
            
            left1  = part1 == 0 ? INT_MIN : nums1[part1-1];
            left2  = part2 == 0 ? INT_MIN : nums2[part2-1];
            right1 = part1 == m ? INT_MAX : nums1[part1];
            right2 = part2 == n ? INT_MAX : nums2[part2];
            
            if(left1 <= right2 and left2 <= right1){
                if((m+n)%2 != 0)
                    return max(left1,left2);
                else
                    return (max(left1,left2) + min(right1,right2))/2.0;
            }
            else if(left1 > right2)  high = part1-1;
            else low = part1+1;   
        }
      return 0.0;     
    }  
double median(vector<int> a, vector<int> b)
{
    // Write your code here.
    int m = a.size(), n = b.size();
        return solve(a,b,m,n);
}