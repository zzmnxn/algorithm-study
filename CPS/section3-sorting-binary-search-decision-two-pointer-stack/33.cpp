// 33. 3등의 성적은?
// 선택 정렬 활요
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    //freopen("input.txt","rt",stdin);
    int n;    
    scanf("%d",&n);
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    for(int i=0;i<n-1;i++){
        int max=i;
        for(int j=i+1;j<n;j++){
            if(arr[max]<arr[j]){
                max=j;
            }
        }
        int tmp=arr[max];
        arr[max]=arr[i];
        arr[i]=tmp;
    }

    int rank=1;
    for(int i=1;i<n;i++){
        if(rank==3) {
            printf("%d",arr[i-1]);
            //rank 갱신되었을 떄 그 다음 꺼 출력하고 있었음
            break;
        }
        if(arr[i]!=arr[i-1]) rank++;
        //printf("%d\n",arr[i]);
    }


    return 0;




}