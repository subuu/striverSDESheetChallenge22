string writeAsYouSpeak(int n) 
{
	// Write your code here.
        if(n==1) return "1";
        else if(n==2) return "11";
        
        string str = writeAsYouSpeak(n-1);
        string ans="";
        char ch=str[0]; int freq = 1;
        
        for(int i=1;i<str.length();i++){
            if(str[i] == ch) freq++;
            else{
                ans += to_string(freq)+ch;
                ch = str[i]; freq = 1;
            }
        }
        ans += to_string(freq)+ch;
        return ans;  
}