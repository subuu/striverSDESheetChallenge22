#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &nums)
{
    // Write your code here.
           int n = nums.size();
       int candidate1 = INT_MAX, candidate2 = INT_MAX;
       int count1 = 0,count2 = 0; 
        
        for(int i= 0; i < n; i++) {
        // We are seeing candidate1 for the first time
        if(candidate1 != INT_MAX && candidate1 == nums[i]){ 
            count1 += 1;
        }else if (candidate2 != INT_MAX && candidate2 == nums[i]) {
            count2 += 1;
        }else if (count1 == 0) {
            candidate1 = nums[i];
            count1 = 1;
        }else if (count2 == 0) {
            candidate2 = nums[i];
            count2 = 1;
        }else {
            count1 -= 1;
            count2 -= 1;
        }
        
    }
        
     // Now we have two potential candidate, verify their candidature
    vector <int> result; 
    int c1=0, c2 = 0;
    
    for(int i= 0; i < n; i++) {
        if(candidate1 != INT_MAX && nums[i] == candidate1) { c1 += 1 ;}
        if(candidate2 != INT_MAX && nums[i] == candidate2) { c2 += 1 ;}
    }
    
    // Append into result if it follows the constraint
    if(c1 > (n/3)) { result.push_back(candidate1); }
    if(c2 > (n/3)) { result.push_back(candidate2); }

    return result;
}