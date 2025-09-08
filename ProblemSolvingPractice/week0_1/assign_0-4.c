#include <stdio.h>
#include <stdlib.h>
// Divide and Conquer

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
        sum=0;
        for(int u=l;u<n;u++){
            sum+=arr[u];
            if(sum>max) max=sum;
        }
    }
    
    printf("%d", max);
    free(arr);

    return 0;
    
}