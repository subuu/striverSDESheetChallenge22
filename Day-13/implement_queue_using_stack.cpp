//https://www.codingninjas.com/codestudio/problems/799482
#include<bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    stack<int> s1,s2;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
          s1.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(isEmpty()) return -1;
        int val;
        if(s2.empty()){
            while(s1.size() > 0){
                s2.push(s1.top());
                s1.pop();
            }
         }
        val = s2.top();
        s2.pop();
        return val;
    }

    int peek() {
        // Implement the peek() function here.
        if(isEmpty()) return -1;
        if(s2.empty()){
            while(s1.size() > 0){
                s2.push(s1.top());
                s1.pop();
            }
         }
        return s2.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return s1.size() == 0 and s2.size() == 0;
    }
};