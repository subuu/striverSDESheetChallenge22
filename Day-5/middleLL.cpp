#include <bits/stdc++.h> 
/****************************************************************

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

*****************************************************************/

Node *findMiddle(Node *head) {
    // Write your code here
     if(!head->next)
            return head;
        if(!head->next->next)
            return head->next;
        
       Node *slow = head, *fast = head;
       while(fast and fast->next){
           slow = slow->next;
           fast = fast->next->next;
       }
           
      return slow;  
        
}