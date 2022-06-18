#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node* mergeTwoLists(Node* first, Node* second) {
    Node *t = new Node(0);
    Node *ans = t; 
    
    while(first && second) {
        if(first->data < second->data) {
            t->child = first; 
            t = t->child; 
            first = first->child; 
        }
        else {
            t->child = second;
            t = t->child; 
            second = second->child; 
        }
    }
    
    if(first) t->child = first; 
    else t->child = second; 
    ans->child->next = NULL; 
    return ans->child; 
}
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
       if (!head || !head->next) 
            return head; 
        head->next = flattenLinkedList(head->next); 
        head = mergeTwoLists(head, head->next); 
        return head; 
}
