#include <stdio.h>
#include <stdlib.h>
//BruteForce
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
        for(int u=l;u<n;u++){
            sum=0;
            // u와 l은 계산할 범위 첨과 끝 
            // 그 사이를 오가는 인덱스는 i
            for(int i=l;i<u;i++){
                sum+=arr[i];
            }
            if(sum>max) max=sum;
        }
    }
    
    printf("%d", max);
    free(arr);

    return 0;
    
}