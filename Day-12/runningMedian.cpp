#include<bits/stdc++.h>
int getMedian(priority_queue<int> &small, priority_queue<int> &large) {
    return small.size() > large.size() ? small.top() : (small.top() - large.top()) / 2;
    }

void addNum(int num,priority_queue<int> &small, priority_queue<int> &large) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop(); 
        }
}

void findMedian(int *arr, int n)
{  
    priority_queue<int> small, large;
    // Write your code here
    for(int i=0;i<n;i++){
        addNum(arr[i],small,large);
        cout<<getMedian(small,large)<<" ";
    } 
}