#include<bits/stdc++.h>
bool findwords(int ind,string s,unordered_map<string,int>&mp, 
               vector<int> &dp){
        if(ind==s.size()){
        return dp[s.size()]=true;}
        
        if(dp[ind]!=-1)return dp[ind];
    
        for(int i=ind;i<s.size();i++){
            if(mp.find(s.substr(ind,i-ind+1))!=mp.end()){
            if(findwords(i+1,s,mp,dp)){return dp[ind]=true;}
            }
        }
        return dp[ind]=false;
}
bool wordBreak(vector <string> & arr, int n, string & target) {
    // Write your code here.
        vector<int> dp(1000,-1);
        unordered_map<string,int>mp;
        for(auto i:arr)mp[i]++;
        return findwords(0,target,mp,dp);
}