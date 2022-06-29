int uniqueElement(vector<int> nums, int n)
{
	// Write your code here
        int low = 0, high = n-2,mid;
        while(low <= high){
           mid = low + (high-low)/2;
            
           if(mid%2 == 0){
               if(nums[mid] != nums[mid+1])
                   high = mid -1;
               else
                   low = mid +1;
           }  
           else{
              if(nums[mid] != nums[mid+1])
                   low = mid + 1;
               else
                   high = mid -1; 
           } 
            
        }
        return nums[low];
}
