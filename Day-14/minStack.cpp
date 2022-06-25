// Implement class for minStack.
#include<bits/stdc++.h>
class Node{
 public:
    int data;
    Node *left;
    Node *right;
    
    Node(int d)
    {
        data =d ;
        left = NULL;
        right = NULL;
    }
    
};
class minStack
{
	// Write your code here.
	public:
		 Node *head,*tail;
         int minVal = INT_MAX;
		// Constructor
		minStack() 
		{ 
			// Write your code here.
              head = tail = NULL;
		}
		
        bool isEmpty(){
            if(!head) return true; 
            else return false;
        }
    
    
		// Function to add another element equal to num at the top of stack.
		void push(int val)
		{
			// Write your code here.
        Node *temp = new Node(val);
        if(head == NULL)
        {
            head = tail = temp;
        }
        else{
             tail->right = temp;
             temp->left = tail;
             tail = temp;
           }
            minVal = min(minVal,val);
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
         if(isEmpty()) return -1; 
           Node *temp = tail;
        int d = tail->data;
        
        if(tail->left)
        {
            tail = tail->left;
            tail->right = NULL;
        }
        else
        {
            head = tail = NULL;
            minVal = INT_MAX;
        }
        delete(temp);
        
        if(tail and d == minVal)
        {   temp = tail;
            minVal = INT_MAX;
            
            while(temp)
            {
               minVal = min(minVal,temp->data);
               temp = temp->left;    
            }
        }
           
           return d; 
          
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{     if(isEmpty()) return -1; 
			// Write your code here.
                return  tail->data;   
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{if(isEmpty()) return -1; 
			// Write your code here.
            return minVal;
		}
};