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
 Node* reverseKGroup(Node* head, int val,int n, int *b) {     
        if(head==NULL || val == n)
            return head;

        int i = b[val];
        while(i==0 and val < n){
            val++; i = b[val];
        }
        if(val == n) return head;
   
        Node* pre = new Node(-1);
        Node* curr = head;
        Node* nxt = head->next;
    
        while(curr and i>0) {
            curr->next = pre;
            pre = curr;
            curr=nxt;
            if(curr)
                nxt=nxt->next;
            i--;
        }    
        head->next = reverseKGroup(curr, val+1,n,b);
        return pre;
    }
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
    return reverseKGroup(head,0,n,b);
}