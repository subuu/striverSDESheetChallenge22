#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* list1, Node<int>* list2)
{
    // Write your code here. 
    if(list1 == NULL and list2 == NULL)
            return NULL;
        else if(list1 == NULL)
            return list2;
        else if(list2 == NULL)
            return list1;
        else{
        Node<int> *head = NULL;
        Node<int> *tail = NULL;
        
         if(list1->data < list2->data)
         {
             head = tail = list1;
             list1 = list1->next;
         }
         else
         {
             head = tail = list2;
             list2 = list2->next;
         }
        
         while(list1 != NULL and list2 != NULL)
         {
             if(list1->data < list2->data)
            {
             tail->next = list1;
             tail = list1;    
             list1 = list1->next;
            }
            else
            {
             tail->next = list2;
             tail = list2;
             list2 = list2->next;
            }
             
         }
            
         while(list1 != NULL)   
         {
             tail->next = list1;
             tail = list1;    
             list1 = list1->next;     
         }
            
          while(list2 != NULL)   
         {
             tail->next = list2;
             tail = list2;    
             list2 = list2->next;     
         }   
            
         return head;
        
        }
        
}