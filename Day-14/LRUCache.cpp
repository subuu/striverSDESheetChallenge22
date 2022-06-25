//https://www.codingninjas.com/codestudio/problems/670276
#include<bits/stdc++.h>
class LRUCache
{
public:
//structure of doubly linked list
    class node{
        public :
        int key;
        int value;
        node *left;
        node *right;
        
        node(int k, int v){
            key = k; value = v;
            left = NULL; right = NULL;
        }
    };
    
    node *head = new node(-1,-1);  // start of doubly linked list
    node *tail = new node(-1,-1);     // end of doubly linked list
    int cachecap=0;                 // capacity of cache
    unordered_map<int,node*> mp;   // to keep track of nodes in cache
    
    LRUCache(int capacity)
    {
        // Write your code here
        cachecap = capacity;
        head->right = tail;
        tail->left  = head;
    }

    int get(int key)
    {
        // Write your code here
         if(mp.find(key) == mp.end()) return -1;      // if key not in cache
        else{
            node *temp = mp[key]; // retrieve node address from hashmap
            
            //remove node from last i.e before tail
            temp->left->right = temp->right;   
            temp->right->left = temp->left;
            
            // add node next to head due to LRU
            head->right->left = temp;
            temp->right = head->right;
            temp->left = head;
            head->right = temp;
            
            return temp->value;
        } 
    }

    void put(int key, int value)
    {
        // Write your code here
        if(mp.find(key) != mp.end()){   
    //if key already exist then update its value and attach next to its head after removing from second last position
            node *temp = mp[key];
            temp->value = value;
            temp->left->right = temp->right;
            temp->right->left = temp->left;
            
            head->right->left = temp;
            temp->right = head->right;
            temp->left = head;
            head->right = temp;
            return;    // no work left out so return
        }
        
        
        if(mp.size() == cachecap){     // if cache is full delete LRU  node
            node *temp = tail->left;
            mp.erase(temp->key);
            
            temp->left->right = tail;
            tail->left = temp->left;
            delete(temp);  
        }
        
           //Add new node
            node *temp1 = new node(key,value);
            mp[key] = temp1;
            
            head->right->left = temp1;
            temp1->right = head->right;
            temp1->left = head;
            head->right = temp1;
    }
};
