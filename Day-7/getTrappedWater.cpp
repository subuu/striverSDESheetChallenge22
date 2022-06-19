#include <bits/stdc++.h> 
long getTrappedWater(long *height, int n){
    // Write your code here.
      long left=0,right=0;  
      long curr =0,last = n-1;
      long res = 0;
        
      while(curr <= last)
      {
          if(height[curr] < height[last])
          {
              if(height[curr] > left)
                 left = height[curr];
              else
                res += (left - height[curr]);
            
            curr++;  
          }
          else
          {
                if(height[last] > right)
                    right = height[last];
                else
                    res += (right - height[last]);
              last--;
          }
      }
        
      return res;  
        
}