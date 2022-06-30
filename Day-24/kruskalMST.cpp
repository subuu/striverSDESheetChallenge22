//https://www.codingninjas.com/codestudio/problems/1082553
#include<bits/stdc++.h>
bool static compare(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

int findParent(int node, vector<int> &parent){
    if(node == parent[node]) return node;
    return parent[node] = findParent(parent[node],parent);
}

void doUnion(int u, int v, vector<int> &parent,vector<int> &rank){
    u = findParent(u,parent);
    v = findParent(v,parent);
    
    if(rank[u] < rank[v]) parent[u] = v;
    else if(rank[v] < rank[u]) parent[v] = u; 
    else{
        parent[v] = u; rank[u]++;
    }
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
    sort(graph.begin(),graph.end(),compare);
    vector<int> parent(n+1),rank(n+1,0);
    for(int i=1;i<=n;i++) parent[i] = i;
    //vector<pair<int,int>> mst; if required edges in mast to be printed
    int cost = 0;
    for(auto &p :graph){
        if(findParent(p[0],parent) != findParent(p[1],parent)){
            cost += p[2];
            //mst.push_back({p[0],p[1]})
            doUnion(p[0],p[1],parent,rank);
        }
    }
   return cost; 
}