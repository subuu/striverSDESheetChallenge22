bool areAnagram(string &str1, string &str2){
    // Write your code here.
    int arr[26]={0};
    for(int i=0;i<str1.size();i++){
        arr[str1[i]-'a']++;
    }
    
    for(int i=0;i<str2.size();i++){
        arr[str2[i]-'a']--;
    }
    
    for(int i=0;i<26;i++){
       if(arr[i] != 0) return false;
    }
   return true; 
}