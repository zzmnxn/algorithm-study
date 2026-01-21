#include <bits/stdc++.h>

using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    unordered_set<string> Strings; // 내장 hash 사용
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        Strings.insert(str);
    }

    vector<string> Set(m);
    int res=0;
    for(int i=0;i<m;i++){
        string str;
        cin>>str;
        if(Strings.find(str)!=Strings.end()){
            res++;
        }
    }
    cout<<res;
    return 0;

}