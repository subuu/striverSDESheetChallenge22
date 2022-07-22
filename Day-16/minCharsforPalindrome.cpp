int minCharsforPalindrome(string str) {
    int l = 0,ans =0,r=0; bool flag = true;
    for(int val=str.length()-1;val>=0;val--){
    l=0; r=val; flag = true;   
    while(l<r){
        if(str[l] == str[r]) { l++;r--;}
        else{
           flag = false;break; 
         }
      }
      if(flag) {r = val;break;}   
    }
    ans = str.length()-r-1;
    
   return ans;
}
