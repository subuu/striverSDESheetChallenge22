int compareVersions(string a, string b) 
{
    // Write your code here
    string str1="",str2=""; int i=0,j=0,n,m,ans=0;
    while(i<a.length() || j < b.length()){
        long long n1=0,n2=0;
        
        while(i<a.length() and a[i] != '.') {
        n1 = n1*10 + 1ll*(a[i]-'0');
        i++;}
        while(j < b.length() and b[j] != '.') {
        n2 = n2*10 + 1ll*(b[j]-'0');
        j++;}
        if(n1 < n2) {ans = -1;break;}
        else if (n1 > n2) {ans = 1;break;}
        i++;j++;
    }

    return ans; 
}