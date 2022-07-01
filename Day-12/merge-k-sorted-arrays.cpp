//https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=1
#include<bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{ // Write your code here. 
    priority_queue <pair<int,pair<int,int>>> pq;
    vector<int> ans;
    for(int i=0;i<arr.size();i++){
        pq.push({-arr[i][0],{i,0}});
    }
    int val,i,j;
    while(pq.size()>0){
        val = -pq.top().first;
        ans.push_back(val);
        i = pq.top().second.first;j = pq.top().second.second;
        pq.pop();
        if(j+1 <arr[i].size()) pq.push({-arr[i][++j],{i,j}});
    } 
    return ans;
}