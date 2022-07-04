int longestIncreasingSubsequence(int nums[], int n)
{
    // Write Your Code here
    int cnt = 0;
   for (int i=1;i <n;i++){
   if (nums[cnt] < nums[i]) {cnt++;nums[cnt] = nums[i];}
   else 
   nums[lower_bound(nums, nums+cnt, nums[i])-nums] = nums[i];   
        }
        return cnt+1;
}
