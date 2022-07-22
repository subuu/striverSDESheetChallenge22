#include<bits/stdc++.h>
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     // Write your code here.
//    sort(arr.begin(),arr.end()); 
//    vector<bool> previous(k+1,false),current(k+1,false);
//       previous[0] =true;
//       if(arr[0] <=k) previous[arr[0]] = true;
    
//      for(int ind=1; ind<n;ind++){
//         current[0]=true;
//         for(int t=1;t<=k;t++){
//            bool notTaken = previous[t];
            
//             bool taken = false;
//             if(arr[ind]<=t)
//                 taken = previous[t-arr[ind]];
                
//             current[t] = notTaken||taken;
//         }
//         previous = current;
//     }
    
//     return previous[k];
// }
#include<bits/stdc++.h>
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
   sort(arr.begin(),arr.end()); 
   vector<bool> dp(k+1,false);
    dp[0] =true;

     for(int ind=0; ind<n;ind++){
        for(int t=k;t>0;t--){
           if(arr[ind]<=t)
               dp[t] = dp[t]||dp[t-arr[ind]];
        }
    }
    return dp[k];
}