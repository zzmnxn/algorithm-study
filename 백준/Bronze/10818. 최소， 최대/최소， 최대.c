#include <stdio.h>
#include <limits.h>

int main(){
    int n, tmp;
    scanf("%d",&n);
    int max,min;
    max=INT_MIN;
    min=INT_MAX;  // INT_MAX limits.h에 정의되어 있음
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        if(max<tmp) max=tmp;
        if(min>tmp) min =tmp;
    }

    printf ("%d %d",min, max );

    return 0;
}