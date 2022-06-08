#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	long long int len = arr.size();

    long long int S = (len * (len+1) ) /2;
    long long int P = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;
     
    for(int i=0;i<arr.size(); i++){
       S -= (long long int)arr[i];
       P -= (long long int)arr[i]*(long long int)arr[i];
    }
     
    missingNumber = (S + P/S)/2;

    repeating = missingNumber - S;

    pair<int,int> ans;

    ans.second = repeating;
    ans.first = missingNumber;

    return ans;
}