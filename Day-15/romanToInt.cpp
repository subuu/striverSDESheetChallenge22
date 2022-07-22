int romanToInt(string s) {
    // Write your code here
     int ans =0;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'I'){
                if(i+1<s.length() and (s[i+1]== 'V' || s[i+1]== 'X')){
                    ans += (s[i+1]== 'V') ? 4 : 9; i++;
                }
                else ans += 1;
            }
            else if(s[i] == 'V') ans+= 5;
            else if(s[i] == 'X'){
                if(i+1<s.length() and (s[i+1]== 'L' || s[i+1]== 'C')){
                    ans += (s[i+1]== 'L') ? 40 : 90; i++;
                }
                else ans += 10;
            }
            else if(s[i] == 'L') ans += 50;
            else if(s[i] == 'C'){
                if(i+1<s.length() and (s[i+1]== 'D' || s[i+1]== 'M')){
                    ans += (s[i+1]== 'D') ? 400 : 900; i++;
                }
                else ans += 100;
            }
            else if(s[i] == 'D') ans+= 500;
            else ans+= 1000;     
        }
        return ans;
}