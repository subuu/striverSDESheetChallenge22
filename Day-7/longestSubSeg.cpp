int longestSubSeg(vector<int> &nums , int n, int k){
    // Write your code here.
     int i=0,j;
        for(j=0; j < nums.size();j++){
            if(nums[j] == 0) k--;
            if(k < 0 and nums[i++]==0) k++;
        }
        return j-i;
}
