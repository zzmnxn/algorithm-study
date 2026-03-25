#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());
    //0, 1번째 수는 서로 다른 두 수로 이루어질 수 없으니 제외한다.    //현재 인덱스 i라고 할때
    //이때, arr의 원소가 음수일수도 있으니 자기 자신을 제외하고 다 후보다.
    //매번 양끝 투 포인터 알고리즘을 돌린다?
    int good=0;
    for(int i=0;i<n;i++){
        int target=arr[i];
        int left=0, right=n-1; 
        int sum=0;
        while(left<right){
            if(left==i ){
                left++;
                continue;
            }else if(right==i){
                right--;
                continue;
            }
            
            sum=arr[left]+arr[right];
            if(sum==target){
                good++;
                break;
            }
            else if(sum>target){
                right--;
            }
            else{
                left++;
            }
        }
    }

    cout<<good;
    return 0;
    

}