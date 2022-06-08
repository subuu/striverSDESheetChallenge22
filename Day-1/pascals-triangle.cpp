//https://leetcode.com/problems/pascals-triangle/
class Solution {
public:
    #include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
     vector<vector<long long int>> vec;
        vector<long long int>v;
        v.push_back(1);
        vec.push_back(v);
        
        if(n == 1)
        {
            return vec;
        }
        
        v.push_back(1);
        vec.push_back(v);
        if(n == 2)
        {
            return vec;
        }
        else
        {  
           for( int i=2;i<n;i++){ 
            v.clear();
            for(int j=0;j<=i ;j++)
            {
                if(j==0 || j == i)
                    v.push_back(1);
                else
                {   long long int value = vec[i-1][j-1] + vec[i-1][j];
                    v.push_back(value);
                }
            }  
             vec.push_back(v);
           }
            
            return vec;
        } 
}

};