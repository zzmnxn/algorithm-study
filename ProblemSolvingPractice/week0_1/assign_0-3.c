#include <stdio.h>
#include <stdlib.h>
//O(n^2) 알고리즘-2

int main(){
    freopen("input.txt","rt",stdin);
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    int* crr=(int*)malloc(sizeof(int)*n); //누적합 array
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    crr[0]=arr[0];
    for(int i=1;i<n;i++){
        crr[i]=crr[i-1]+arr[i];
    }
    //누적합 array 구함
    int max=0;
    int sum;
    for(int i=1;i<n;i++){
        for(int j=i;j<n;j++){
            sum=crr[j]-crr[i-1];
            if(sum>max) max=sum;
        }
    }

    printf("%d", max);
    free(arr);

    return 0;
    
}