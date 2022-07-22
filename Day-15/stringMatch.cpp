#include<bits/stdc++.h>
void search(string &txt, string &pat, int q, vector<int> &ans) 
{ 
    int M = pat.length(), N = txt.length(); 
    int i, j, p = 0, t = 0, h = 1,d=31; 

    for (i = 0; i < M - 1; i++) h = (h * d) % q; 
    for (i = 0; i < M; i++) 
    {   p = (d * p + pat[i]) % q; 
        t = (d * t + txt[i]) % q;} 

    for (i = 0; i <= N - M; i++) 
    { 
        if ( p == t ) 
        {   for (j = 0; j < M; j++) if (txt[i+j] != pat[j]) break;
            if (j == M) ans.push_back(i);    
        } 
  
        if ( i < N-M ) 
        {   t = (d*(t - txt[i]*h) + txt[i+M])%q; 
            if (t < 0)  t = (t + q);
        } 
    } 
}
vector<int> stringMatch(string &str, string &pat) {
    // Write your code here
    vector<int> ans;
    search(str,pat,29,ans);
    return ans;
}