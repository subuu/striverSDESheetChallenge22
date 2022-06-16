//https://www.codingninjas.com/codestudio/problems/799354
#include<bits/stdc++.h> 
vector<int> nextGreater(vector<int> &nums, int n) {    
    // Write your code here 
      vector <int> nge(n, -1);
      stack <int> st;
      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i ]) {
          st.pop();
        }

        if (i < n and !st.empty()) {
            nge[i] = st.top();
        }
        st.push(nums[i ]);
      }
      return nge;
}