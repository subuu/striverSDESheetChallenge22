//https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int m, int n, int k)
    {
        
    int left = min(arr1[0],arr2[0]), right = max(arr1[m-1],arr2[n-1]); // The range of where ans can lie.
        int ans = INT_MAX; // We have to find min of all
                              // the ans so take .
 
    // using binary search to check all possible values of
    // kth element
    while (left <= right) {
        int mid = (left + right) / 2;
        int up_cnt = upper_bound(arr1, arr1 + m, mid) - arr1;
        up_cnt += upper_bound(arr2, arr2 + n, mid) - arr2;
 
        if (up_cnt >= k) {
            ans = min(ans,mid); // find the min of all answers.
            right= mid - 1; // Try to find a smaller answer.
        }
        else
            left = mid + 1; // Current mid is too small so
                            // shift right.
    }
 
    return ans;}
};