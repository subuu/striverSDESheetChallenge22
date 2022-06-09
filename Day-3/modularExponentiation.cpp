#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
	// Write your code here. 
   long long ans = 1;
  long long p =x;  
  long long nn = n;
  if (nn < 0) nn = -1 * nn;
  while (nn) {
    if (nn % 2) {
      ans = (ans * p)%m;
      nn = nn - 1;
    } else {
      p = (p * p)%m;
      nn = nn / 2;
    }
  }

  return (int)ans%m;
}