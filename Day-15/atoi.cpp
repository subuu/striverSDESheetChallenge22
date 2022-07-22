#include<climits>
int atoi(string s) {
    // Write your code here.
   int len = s.length(), index=0,sign =1,res =0;    
   while(index <len and s[index] == ' ') index++;  
   if(s[index] == '-' || s[index] == '+'  ) sign = s[index++] == '-' ? -1 : 1;
        
   while(index < len)       
        {   
            if((s[index] >='0' and s[index] <='9')){
            if(res > INT_MAX/10 || res * 10 > INT_MAX - (s[index] - '0'))
                return sign == 1 ? INT_MAX : INT_MIN;
    
            res = res * 10 + (s[index]-'0');}
            index++;
        }
    return sign*res; 
}