#include <bits/stdc++.h.>
using namespace std;

int min_steps(int n){
    int result=0;
    int i;
    for(i=2;i*i<=n;i++){
        while(n%i==0){
            n/=i;
            result+=i;
        }
    }
    if(n>1) result+=n;
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    cout<<min_steps(n);
    return 0;
}