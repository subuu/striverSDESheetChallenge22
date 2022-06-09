#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n) {
    // Write your code here  
        unordered_set<int> hashSet(nums.begin(), nums.end()); 
        int longestStreak = 0;

  for (int num: nums) {
    if (!hashSet.count(num - 1)) {
      int currentNum = num;
      int currentStreak = 1;

      while (hashSet.count(currentNum + 1)) {
        currentNum += 1;
        currentStreak += 1;
      }

      longestStreak = max(longestStreak, currentStreak);
    }
  }

  return longestStreak; 
}