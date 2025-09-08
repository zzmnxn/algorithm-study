#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int a;
    scanf("%d",&a);
    int result=0;
    while(n>=1){
        if(n&1){
            //n의 마지막 비트가 1인지 확인(비트연산자)

            result =result*a;
        }
        a=a*a;
        //a를 제곱

        //n을 오른쪽으로 1비트 시프트
        n>>=1;

    }

    return 0;
     
    

}