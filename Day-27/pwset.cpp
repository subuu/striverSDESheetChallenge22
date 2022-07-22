#include<bits/stdc++.h>
void solve(vector<int> &v, int ind, vector<vector<int>> &ans, 
           vector<int> &temp){
    if(ind == v.size()){
        if(temp.size() > 0) ans.push_back(temp);
        return;
    }
    
    temp.push_back(v[ind]);
    solve(v,ind+1,ans,temp);
    temp.pop_back();
    solve(v,ind+1,ans,temp);
}

vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
            int n = v.size(); 
            vector<vector<int>> ans; vector<int> temp;
            solve(v,0,ans,temp); 
         return ans; 
}