//https://www.codingninjas.com/codestudio/problems/lfucache_3114758
#include<bits/stdc++.h>
struct node{
   int key,value,count;
   node *left;
   node *right;
   
   node(int k, int v){
       key = k;
       value = v;
       left = NULL;
       right = NULL;
       count=1;
   }  
};

struct flist{
  int size;
  node *head;
  node *tail;
    
  flist(){
      head = new node(-1,-1);
      tail = new node(-1,-1);
      size =0;
      head->right = tail;
      tail->left = head;
  }  
    
  void addNode(node *n){
      node *temp = head->right;
      n->right = temp;
      temp->left = n;
      head->right = n;
      n->left = head;
      size++;
  }  
    
  void removeNode(node *n){
      node *temp = n->left;
      temp->right = n->right;
      n->right->left = temp;
      size--;
  }  
};

class LFUCache
{   unordered_map<int, node*> nodemp;
    unordered_map<int, flist*> freqmp;
    int currsize,maxsize, minfreq;  
public:
    LFUCache(int capacity)
    {
        // Write your code here.
         maxsize = capacity;
        currsize = minfreq = 0;
    }

     void updatefreqList(node *n){
        nodemp.erase(n->key);
        freqmp[n->count]->removeNode(n);        
        
        if(n->count == minfreq and freqmp[n->count]->size==0) minfreq++;
        flist *l = new flist();
        if(freqmp.find(n->count+1) != freqmp.end()) l = freqmp[n->count+1];
        
        n->count += 1;
        l->addNode(n);
        freqmp[n->count] = l;
        nodemp[n->key] = n;  
    }
 
    int get(int key)
    {
        // Write your code here.
         if(nodemp.find(key) == nodemp.end()) return -1;
       else{
           node *temp = nodemp[key];
           updatefreqList(temp);
           return temp->value;
       } 
    }

    void put(int key, int value)
    {
        // Write your code here.
         if(maxsize==0) {}
        else if(nodemp.find(key) != nodemp.end()){
            node *temp = nodemp[key];
            temp->value = value;
            updatefreqList(temp);
        }
        else{
            if(currsize == maxsize){
                flist *l = freqmp[minfreq];
                nodemp.erase(l->tail->left->key);
                freqmp[minfreq]->removeNode(l->tail->left);
                currsize--;
            }
            
            currsize++;
            minfreq = 1;
            flist *l = new flist();
            
            if(freqmp.find(minfreq) != freqmp.end()) l = freqmp[minfreq];
            
            node *n = new node(key,value);
            l->addNode(n);
            nodemp[key] = n;
            freqmp[minfreq] = l;         
        }
    }
};
