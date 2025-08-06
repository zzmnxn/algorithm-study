/*********30. 3의 개수는?(large)******/
//구글 인터뷰 
//입력이 매우 큰 숫자
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
 * 각 자리에서 3이 얼마나 등장하느냐 수학적으로 think
 * 
 */