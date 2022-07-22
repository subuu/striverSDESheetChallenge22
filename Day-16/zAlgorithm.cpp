int zAlgorithm(string s, string p, int n, int m)
{
    int ans=0;
    for(int i=0;i<=n-m;i++){
        if(s[i]==p[0]){
            int l=1,r=i+1;
            while(p[l] == s[r] and r<n){
                    r++;l++;
                }
             if(l==m) ans++;
            }
    }

    return ans;
}