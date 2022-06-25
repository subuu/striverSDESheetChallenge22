//https://www.codingninjas.com/codestudio/problems/1112581
#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    if(n==0) return {};
    if(n==1) return {-1};
    
    vector<int> ans(n,-1);
    stack<int> st;
    st.push(arr[n-1]);
    
    for(int i=n-2;i>=0;i--){
        while(!st.empty() and st.top() >= arr[i]) st.pop();
        if(i<n and !st.empty()) ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;   
}