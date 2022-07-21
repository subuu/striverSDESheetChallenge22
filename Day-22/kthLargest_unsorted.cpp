int partition(vector<int>& arr, int l, int r) {
    int i=l-1,pivot = arr[r]; 
    for (int j = l; j <= r-1; j++) {
        if (arr[j] <pivot ) { 
            i++;swap(arr[i], arr[j]) ;
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

int kthLargest(vector<int>& arr, int size, int k)
{
	// Write your code here.
    int l = 0, r = size - 1, ans;
    while(true) {
        int index = partition(arr, l, r);
        if (index == size-k) {
            ans = arr[index];
            break;
        }
        else if (index < size-k) l = index + 1;
        else  r = index - 1;
        
    }
    return ans;
}