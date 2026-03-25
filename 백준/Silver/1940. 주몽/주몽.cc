#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin>>N;
    cin>>M;
    vector<int> arr(N);

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());

    int left=0, right=N-1;
    int sum=0;
    int result=0;

    while(left<right){
        sum= arr[left]+arr[right];

        if(sum==M){
            result++;
            left++;
            right--;
        }
        else if(sum>M){
            right--;
        }
        else{
            left++;
        }
    }

    cout<<result;

    return 0;
}