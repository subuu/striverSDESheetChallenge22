#include <bits/stdc++.h> 
/********************************

    Following is the class structure of the Node class:
    
    class Node
    {
    	public:
    	    int data;
    	    Node *next;
    	    Node(int data)
    	    {
    	        this->data = data;
    	        this->next = NULL;
    	    }
    };

********************************/
Node *rotate(Node *head, int k) {
     // Write your code here.
     if(!head || k==0)
           return head;
        else
        {    
            Node* temp = head; 
            int n =0;
            
            while(temp)
            {
                temp = temp->next; 
                n++;
            }
            
            k = k % n;
            int i=1;
            
            temp = head;
            while(i< n-k)
            {
                temp = temp->next;
                i++;
            }
            
            Node* temp1 = temp;
            while(temp1->next) temp1 = temp1->next;
            
            
            temp1->next = head;
            head = temp->next;
            temp->next = NULL;
            
            return head;
        }
}