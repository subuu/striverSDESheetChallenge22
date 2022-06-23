string kthPermutation(int n, int k) {
    // Write your code here.
    int fact = 1; string ans=""; vector<int> num;
        
       for(int i=1;i<n;i++){
           fact *= i; num.push_back(i);
       }
       num.push_back(n);
        k--;
      while(true){
          ans += to_string(num[k/fact]);
          num.erase(num.begin()+k/fact);
          
          if(num.size() == 0) break;
          k %= fact;
          fact /= num.size();
      }  
        
      return ans;  
        
}
