#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    int n = intervals.size();
       
       if(n==0 || n==1) 
           return intervals;
                
       sort(intervals.begin(),intervals.end());
       
       vector<vector<int>> vec;     
       int s = intervals[0][0],e = intervals[0][1]; 
       
       for(int i=1;i<n;i++)
       {
           if(intervals[i][0] < e)
           {
               e = max(e,intervals[i][1]);
               
           }
           else if(intervals[i][0] == e)
           {
               e = intervals[i][1];
           }
           else
           {
               e = max(e,intervals[i-1][1]);
               vector<int> v;
               
               v.push_back(s);v.push_back(e);
               vec.push_back(v);
               s =   intervals[i][0]; e = intervals[i][1];              
           }      
       }
        
        vector<int> v;
        v.push_back(s);v.push_back(e);
        vec.push_back(v); 
        
        return vec;
        
}
