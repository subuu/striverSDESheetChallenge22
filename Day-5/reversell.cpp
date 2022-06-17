#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
  LinkedListNode<int> *h1= NULL;

 LinkedListNode<int>* reverse(LinkedListNode<int>* head) {
        
        if(head == NULL)
            return NULL;
        else if(head->next == NULL)
        {   h1 = head; 
            return head;
        }
        else
        {
           LinkedListNode<int> *temp  =  reverse(head->next);   
            temp->next = head;
            return head;
        }   
    }
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    if(head == NULL)
            return NULL;
        else if(head->next == NULL)
            return head;
        else
        {
           LinkedListNode<int> *temp = reverse(head);
           temp->next = NULL;
           return h1; 
        }
}