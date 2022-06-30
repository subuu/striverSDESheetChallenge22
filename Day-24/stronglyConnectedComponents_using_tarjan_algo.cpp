//https://www.codingninjas.com/codestudio/problems/985311
#include<bits/stdc++.h>
void findSCC_Tarjan(int node,vector<int> &low,vector<int> &disc,stack<int> &st,
vector <bool> &inStack,vector<vector<int>> &neighbours,vector<vector<int>> &ans){
    static int time = 0;
    low[node] = time ;disc[node] = time; time++;
    st.push(node); inStack[node] = true;
    
    for(auto &p : neighbours[node]){
        if(disc[p] == -1){
            findSCC_Tarjan(p,low,disc,st,inStack,neighbours,ans);
            low[node] = min(low[node],low[p]);//if adjacent node has seen back edge
        }
        else if(inStack[p]) low[node] = min(low[node],disc[p]); //condition for back edge
     }
    
    if(low[node] == disc[node]) //head of SCC, so put all its nodes in the ans vector 
    {   //scc vector contains 1 single SCC
        vector<int> scc; int val;
        while(st.top() != node){
            val = st.top(); scc.push_back(val);
            inStack[st.top()] = false; st.pop();
        }
        val = st.top(); scc.push_back(val);
        inStack[st.top()] = false; st.pop();
        ans.push_back(scc);
    }
}


vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> neighbours(n);
    for(int i=0;i<edges.size();i++) 
        neighbours[edges[i][0]].push_back(edges[i][1]);
    
    vector<int> low(n,-1);  //node discovered lowest time -> keeps on changing
    vector<int> disc(n,-1); //node discover for 1st time. -> fixed for each node
    vector<bool> inStack(n,false); //to check whether adjacent visited edge is cross-edge/back-edge
    /*
     if disc[adj node] != -1 i.e. already visited and inStack[adj node] == true i.e. it is a back edge.
     if disc[adj node] != -1 i.e. already visited and inStack[adj node] == false i.e. it is a cross edge.
    */
    stack<int> st;
    
    for(int i=0;i<n;i++){
        if(disc[i] == -1)
            findSCC_Tarjan(i,low,disc,st,inStack,neighbours,ans);
    }
   return ans; 
}