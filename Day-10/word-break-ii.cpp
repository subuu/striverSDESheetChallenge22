#include<bits/stdc++.h>
void findword(string s,string str,unordered_map <string,int> &mp,
vector<string> &ans){
        //Base Case
        if(s.length()==0){     // Traverse the complete string
        str.pop_back();        // Remove space from the end of string
        ans.push_back(str);    
        return;}
       
           //Recursive case
        for(int i=0;i<s.length();i++){
        string prefix=s.substr(0,i+1); //prefix from 0 to i position
        string sufix=s.substr(i+1);    // suffix from (i+1) to (s.length()-1)
            if(mp[prefix]){           // If prefix exist in dictionary
                string str1 = str + prefix+" "; 
                findword(sufix,str1,mp,ans);}           
        }
    }
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
   unordered_map <string,int> mp; //To find words in dictionary in constant time
   vector<string> ans;            // To store the final result
   for(auto p : dictionary)  // Fill the dictionary
        mp[p]=1;
    findword(s,"",mp,ans);
    return ans;
}