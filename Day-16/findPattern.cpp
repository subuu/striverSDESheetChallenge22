void computeLPSArray(string pat, int M, int* lps)
{   int len = 0;
    lps[0] = 0; // lps[0] is always 0
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++; lps[i] = len;i++;
        }
        else{
            if (len != 0) len = lps[len - 1];
            else {
                lps[i] = 0;i++;
            }
        }
    }
}
bool KMPSearch(string pat, string txt)
{
    int M = pat.length(), N = txt.length(), lps[M];
    computeLPSArray(pat, M, lps);
 
    int i = 0,j = 0; // index for pat[]
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++; i++;
        }
 
        if (j == M) {
            return true;
        }
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0) j = lps[j - 1];
            else i = i + 1;
        }
    }
  return false;  
}
bool findPattern(string p, string s)
{
    // Write your code here.
    return KMPSearch(p,s);
}