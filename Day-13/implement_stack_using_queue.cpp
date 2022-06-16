//https://www.codingninjas.com/codestudio/problems/795152
#include<bits/stdc++.h>
class Stack {
	// Define the data members.
   queue<int> q; 
   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q.size() == 0;
    }

    void push(int element) {
        // Implement the push() function.
          int s = getSize();
        q.push(element);
        for(int i=0;i<s;i++)
        {
            q.push(q.front()); q.pop();
        }
    }

    int pop() {
        // Implement the pop() function.
        if(isEmpty()) return -1;
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        // Implement the top() function.
          if(isEmpty()) return -1;
          return q.front();
    }
};