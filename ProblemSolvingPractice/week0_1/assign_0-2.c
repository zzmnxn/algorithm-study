#include <stdio.h>
#include <stdlib.h>
//O(n^2) 알고리즘
//누적합 이용


int main(){
    freopen("input.txt","rt",stdin);
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int max=0;
    int sum;
    for(int l=0;l<n;l++){
        sum=0; //새로운 시작점마다 합을 0으로 초기화
        for(int u=l;u<n;u++){
            //끝점 u를 확장해 나감
            sum+=arr[u];
            //sum l~u-1에 u번째 원소를 더하면 sum u가 됨(누적합)
            if(sum>max) max=sum;
        }
    }
    
    printf("%d", max);
    free(arr);

    return 0;
    
}