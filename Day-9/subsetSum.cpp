#include<bits/stdc++.h>
 void solve(vector<int> &nums,int n, int ind, int sum,vector<int> &ans){
    if (ind == n)
    {ans.push_back(sum); return;}
   
   solve(nums,n,ind+1,sum,ans); 
   solve(nums,n,ind+1,sum+nums[ind],ans);    
 }

vector<int> subsetSum(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();
    // Write your code here.
    solve(nums,n,0,0,ans);
    sort(ans.begin(),ans.end());
    return ans;
}