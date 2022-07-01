#include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &A, vector<int> &B, int n, int C){
	// Write your code here.
 sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    priority_queue<pair<int,pair<int,int>>> pq;
    map<pair<int,int>,int> mp;
    vector<int> ans;
    
    int i= A.size()-1, j = B.size()-1,val;
    val = A[i] + B[j];
    pq.push({val,{i,j}}); mp[{i,j}]=val;
    
    while(C!=0){
        val = pq.top().first; 
        ans.push_back(val);C--;
        i= pq.top().second.first; j = pq.top().second.second;
        pq.pop();
        
        if(mp.find({i-1,j}) == mp.end()){
           val = A[i-1] + B[j];
           pq.push({val,{i-1,j}});mp[{i-1,j}]=val; 
        }
        
        if(mp.find({i,j-1}) == mp.end()){
           val = A[i] + B[j-1];
           pq.push({val,{i,j-1}}); mp[{i,j-1}]=val; 
        }
    }
   return ans; 
}