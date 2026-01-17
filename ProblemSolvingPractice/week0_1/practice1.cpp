#include <bits/stdc++.h>
using namespace std;

int maxSubArrayDnC(const vector<int>& X, int L, int U){
    if(L==U){
        return max(0, X[L]);
    }
    
    int M= L+ (U-L)/2;

    int MaxA= maxSubArrayDnC(X,L,M);

    int MaxB= maxSubArrayDnC(X,M+1,U);

    int sum=0;
    int MaxCA=0;

    for(int i=M;i>=L;i--){
        sum+=X[i];
        MaxCa = max(MaxCA, sum);
    }
}