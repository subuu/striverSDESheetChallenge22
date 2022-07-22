#include<bits/stdc++.h>
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
//Write your coode here.
    vector<int> ans;
    sort(arr.begin(),arr.end());
    
    for(auto p : queries){
        if(p[1] < arr[0]) ans.push_back(-1);
        else{
            int maxval = 0;
            for(int i=0;i<arr.size();i++){
                if(arr[i] <= p[1])
                maxval = max(maxval,p[0]^arr[i]);
                else break;
            }
            ans.push_back(maxval);
        }
    }
    return ans;
}