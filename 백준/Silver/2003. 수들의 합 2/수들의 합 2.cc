#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n, m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int left=0, right=0;
    int result=0;
    int tmp=0; 

    while(true){
       if(tmp>=m){
            if(tmp==m) result++;
            tmp-=arr[left++];

       }
       else if(right ==n){
        //합이 목표보다 작을 때
        // 더이상 더할 숫자도 없는거임
        break;
       }
       else{
        //합이 작으면 r을 움직여서 더한다.
        tmp+=arr[right++];
       }
    }

    cout<<result;

}