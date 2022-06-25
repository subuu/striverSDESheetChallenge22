//https://www.codingninjas.com/codestudio/problems/1058184
#include<bits/stdc++.h> 
int largestRectangle(vector<int> &heights) {
   // Write your code here.
   stack<int>st;
   int maxarea = 0,ht=0,wt=0,n=heights.size(); 
  
   for(int i=0;i<=n;i++){
      while(!st.empty() and (i==n || heights[st.top()] >= heights[i])) 
      {
          ht = heights[st.top()];
          st.pop();
          wt = st.empty() ? i : i-st.top()-1;
          maxarea = max(maxarea,ht*wt);
      }
      st.push(i); 
   } 
   return maxarea;    
 }