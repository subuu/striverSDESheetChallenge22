//https://www.codingninjas.com/codestudio/problems/k-most-frequent-elements_3167808?topList=striver-sde-sheet-problems
#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &nums)
{
    // Write your code here.
     priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        
        for(auto p : mp){
            pq.push({p.second,p.first});
        }
        
        nums.clear(); int val;
        while(k--)
        {
            val = pq.top().second;
            nums.push_back(val); pq.pop();
        }
       sort(nums.begin(),nums.end());
       return nums;
}