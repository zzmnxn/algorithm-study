/***************32. 선택정렬 */
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
    int n,i,tmp;
    scanf("%d",&n);
    vector<int> arr(n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int minIdx;
    for(int i=0;i<n-1;i++){
        minIdx=i; 
        for(int j=i+1;j<n;j++){
            if(arr[minIdx]>arr[j]){
                minIdx=j;
            }
        }
        tmp=arr[minIdx];
        arr[minIdx]=arr[i];
        arr[i]=tmp;
    }

    for(int v : arr){
        printf("%d ",v);
    }

    return 0;


}