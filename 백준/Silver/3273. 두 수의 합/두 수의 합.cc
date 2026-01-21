#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,x;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i]; // 저장되는 거 1 based
    }
    cin>>x;
    vector<int> hash(x+1); //1~x까지 1 based
    int result=0;
    for(int a : arr){
        if(a>=x) continue; // a가 hash table size보다 크면 안됨
        hash[a]=1; // hash 테이블에 array의 원소 있으면 1로 저장
    }

    for(int i =1 ;i<x;i++){ //모든 a가 hash table에 들어간 거 아니니
        //여기는 인덱스 기반으로
        if(hash[i]) { 
            if(hash[x-i]) result++;
        }
    }

    cout<<result/2;
    
    return 0;
}