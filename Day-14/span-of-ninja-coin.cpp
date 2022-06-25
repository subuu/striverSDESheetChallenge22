//https://www.codingninjas.com/codestudio/problems/span-of-ninja-coin_1475049
#include<bits/stdc++.h>
int solve(int price,stack<pair<int, int>> &s) {
        int res = 1;
        while (!s.empty() && s.top().first <= price) {
            res += s.top().second;
            s.pop();
        }
        s.push({price, res});
        return res;
    }
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    stack<pair<int, int>> s;
    for(int i=0;i<price.size();i++)
        price[i] = solve(price[i],s);
   return price; 
}