int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
    int index = 0;
        
        for(int val : arr)
        {
            if(index < 1 || val > arr[index-1])
                 arr[index++] = val;
        }
        
        return index;
}