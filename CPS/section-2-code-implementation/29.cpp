/*********29. 3의 개수는?(small)******/
//구글 인터뷰 
#include <stdio.h>

int main(){
    //freopen("Input.txt","rt",stdin);
    int n;
    scanf("%d",&n);
    int i=3;
    int count=0;
    while(i<=n){
        int t=i;
        while(t>1){
            if(t%10==3) count++;
            t/=10;
        }
        i++;
    }
    printf("%d",count);

    return 0;

}
/***********
 * 모범 답안과 비슷
 */