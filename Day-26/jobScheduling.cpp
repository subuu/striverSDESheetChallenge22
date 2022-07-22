#include<bits/stdc++.h>
bool static comparison(vector<int> a, vector<int> b) {
         return (a[1] > b[1]);
      }
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
      sort(jobs.begin(), jobs.end(), comparison);
      int maxval = jobs[0][0], n = jobs.size();
      for (int i = 1; i < n; i++) {
         maxval = max(maxval, jobs[i][0]);
      }

      vector <int> slot(maxval+1,-1);
      int jobProfit = 0;

      for (int i = 0; i < n; i++) {
         for (int j = jobs[i][0]; j > 0; j--) {
            if (slot[j] == -1) {
               slot[j] = i;
               jobProfit += jobs[i][1];
               break;
            }
         }
      }

      return jobProfit;
}
