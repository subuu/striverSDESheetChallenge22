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
    void createLL(int data,Node * &head, Node *&tail)
    {
        Node *node  = new Node(data);
         if(head == NULL)
             head = tail = node;
         else
            {
              tail->next = node; tail = node;
            }             
    }
    
Node *addTwoNumbers(Node *l1, Node *l2)
{
    // Write your code here.
    int carry = 0;
    Node *head = NULL,*tail = NULL;
    Node *l3 = l1;
    Node *l4 = l2;    
        
        if(l1 == NULL and l2 == NULL)
           return NULL;
        else if (l1 == NULL)
           return l2;
        else if (l2 == NULL)
           return l1;
        else {
            
            int data;
            while(l3 != NULL and l4 != NULL )
            {
                data = l3->data + l4->data + carry;
                carry = data/10; data = data%10;
                createLL(data,head,tail); 
                l3 = l3->next; l4 = l4->next;
            }
            
            while( l3 != NULL)
            {
                data = l3->data + carry;
                carry = data/10; data = data%10;
                createLL(data,head,tail); 
                l3 = l3->next; 
            }
            
             while( l4 != NULL)
            {
                data = l4->data + carry;
                carry = data/10; data = data%10;
               createLL(data,head,tail); 
                l4 = l4->next; 
            }
                
            if(carry) createLL(carry,head,tail); 
        return head;    
     }
}