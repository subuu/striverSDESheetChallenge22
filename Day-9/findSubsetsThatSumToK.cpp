#include<bits/stdc++.h>
void findCombination(int ind, int target, vector <int> &arr, vector <vector < int>> &ans, vector <int> &ds) {
      if (ind == arr.size()) {
        if (target == 0) ans.push_back(ds);
        return;
      }
      // pick up the element 
      ds.push_back(arr[ind]);
      findCombination(ind+1, target - arr[ind], arr, ans, ds);
      ds.pop_back();
      findCombination(ind + 1, target, arr, ans, ds);
    }

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
      vector <vector<int>> ans;
      vector <int> ds;
      findCombination(0, k, arr, ans, ds);
      return ans;
}