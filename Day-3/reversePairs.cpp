#include <bits/stdc++.h> 
 int Merge(vector<int>& nums, int low,int mid ,int high){
        
        int inversion = 0, index2 = mid+1;
        // count possible reverse pairs
        for(int index1 = low; index1 <= mid; index1++){
            while(index2 <= high and nums[index1] > 2LL * nums[index2])                    
                  index2++;
           inversion += index2 - (mid+1);   
        }
        
        //normal merge starts
        vector<int> temp; int left = low, right = mid+1;
        while(left <= mid and right <= high){
            if(nums[left] <= nums[right]) temp.push_back(nums[left++]);
            else temp.push_back(nums[right++]);     
        }
        
        while(left <= mid )  temp.push_back(nums[left++]);
        while(right <= high) temp.push_back(nums[right++]);
        
        for(int i=low; i<=high;i++) nums[i] = temp[i-low];
        return inversion;
    }
   
    int MergeSort(vector<int>& nums, int low, int high){
     
        if(low >= high) return 0;
        int mid = low + (high - low)/2;
        int inversion = 0;
        inversion += MergeSort(nums, low, mid);
        inversion += MergeSort(nums, mid+1, high);
        
        inversion += Merge(nums, low, mid, high);
        return inversion;   
    }
    
   
  
    int reversePairs(vector<int> &arr, int n){
	// Write your code here.	
     return MergeSort(arr,0,arr.size()-1);
    }