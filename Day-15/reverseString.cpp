#include<bits/stdc++.h>
string reverseString(string str)
{
    // Write your code here.
    vector<string> ans;
    string s="";
    for(int i=0;i<str.length();i++){
        if(str[i] == ' '){
            if(!s.empty()) ans.push_back(s) ;
            s="";
        }
        else
            s+= str[i];
    }
    if(!s.empty()) ans.push_back(s);
    
    s="";
    for(int i=ans.size()-1;i>=0;i--)
          s += ans[i]+' ';
    
   s.pop_back(); 
   return s; 
}