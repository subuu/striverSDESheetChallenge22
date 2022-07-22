#include<bits/stdc++.h>
struct Node{
public:
    Node *child[2];
    Node(){
        this->child[0] = NULL; 
        this->child[1] = NULL;
    }
};

class trie{
 public:   
 Node *newNode;
    trie(){ newNode = new Node();}
    
    void insert(int x){   
        Node *t = newNode;
        bitset<32> bs(x);
        
        for(int j=31; j>=0; j--){
            if(!t->child[bs[j]]) t->child[bs[j]] = new Node(); 
            t = t->child[bs[j]];
        }    
    }
    
    int maxXOR(int n){
        Node *t = newNode;
        bitset<32> bs(n);
        int ans=0; 
        for(int j=31; j>=0; j--){
            if(t->child[!bs[j]]) 
                {   ans += (1<<j);
                    t = t->child[!bs[j]]; 
                }
            else 
                t = t->child[bs[j]];
        }
        return ans;
    }   
};

int maximumXor(vector<int> nums)
{
    // Write your code here.
        trie *t = new trie();
        for(auto &n : nums) t->insert(n); 
        
        int ans=0; 
        for(auto n : nums){
            ans = max(ans, t->maxXOR(n));  
        }
        return ans;
}