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

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
        if(!head || K ==0) return head;
        LinkedListNode<int>* l2= head;
        LinkedListNode<int>* l3 = new LinkedListNode<int>(-1);
        l3->next = head;
        int size = K-1;
        
        if(size == 0)
        {
           while(l2->next != NULL) {l3 = l3->next;l2 = l2->next;}
            l3->next = NULL;
        }
        else{
            while(l2->next !=NULL && size > 0) {l2 = l2->next; size--;}         
            while(l2->next !=NULL){l2 = l2->next; l3 = l3->next; }
             l3->next = l3->next->next;       
          }
        
        if(l3->data == -1) head = l3->next;
        return head;
}