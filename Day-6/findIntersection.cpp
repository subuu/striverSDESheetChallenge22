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

int findIntersection(Node *headA, Node *headB)
{
    Node *l3 = headA;
    Node *l4 = headB;

    int len1=0,len2=0;

    while(l3 != NULL)
    {
        l3 = l3->next; len1++;
    }

    while(l4 != NULL)
    {
        l4 = l4->next; len2++;
    }

     
    l3 = headA;
    l4 = headB;

    if(len1 > len2)
    {
        int diff = len1 - len2;
        while(diff--)
        {
           l3 = l3->next;
        }
    }
    else
    {
        int diff = len2 - len1;
        while(diff--)
        {
           l4 = l4->next;
        }
    }

    while(l3 != l4 and l3 and l4)
     {
         l3 = l3->next; l4 = l4->next;
     }

     if (l3==NULL || l4==NULL) return -1;
  return l3->data;
}
