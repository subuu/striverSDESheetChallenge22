#include<bits/stdc++.h>
class Kthlargest {
public:
   priority_queue<int> pq;
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here
       for(int &p : arr) pq.push(-p);
    }

    void add(int num) {
        // Write your code here.
        pq.push(-num);
        pq.pop();
    }

    int getKthLargest() {
       // Write your code here.
       return -pq.top(); 
    }

};