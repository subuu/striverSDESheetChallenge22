 void findPermute(int index,string &s,vector<string>&ans){
        if(index == s.size()){
            ans.push_back(s); return;
        }
        
        for(int i=index;i<s.size();i++){
            swap(s[index], s[i]);
            findPermute(index+1,s,ans);  //recursion
            swap(s[index], s[i]); //backtracking
        }    
    }
    
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    findPermute(0,s,ans);
    return ans; 
}