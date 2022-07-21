#include<bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    vector<int> ans;
    unordered_map<int,int> mp; int i=0;
    while(k--) {
     mp[arr[i++]]++;   
    }
    k=0;
    ans.push_back(mp.size());
    
    for(int j = i;j<arr.size();j++){
        if(mp[arr[k]] == 1) mp.erase(arr[k]);
        else
            mp[arr[k]]--;
        k++;
        mp[arr[j]]++;
        ans.push_back(mp.size()); 
    }
    return ans;
}
