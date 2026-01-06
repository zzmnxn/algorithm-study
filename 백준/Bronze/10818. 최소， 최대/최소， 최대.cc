#include <bits/stdc++.h>
//ctr + alt +n

using namespace std;

int main(){
    int n;
    int tmp;
    int max = -1000001;
    int min = 1000001;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(max<tmp) max=tmp;
        if(min>tmp) min =tmp;
    }
    cout<<min<<" "<<max;
    return 0;
}