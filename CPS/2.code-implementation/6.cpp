//6. 숫자만 추출
#include <stdio.h>
//#include <stdbool.h>
//bool 타입 사용시 헤더파일 주의 
int main(){
    //freopen("input.txt","rt",stdin);
    char arr[50];
    scanf("%s",arr);
    int idx=0;
    int result=0;

    while(arr[idx]!='\0'){
        if(arr[idx]<'0'|| arr[idx]>'9') {
            idx++; //반복문 증가 조건 잘 헤아리기
            continue;
        } 
        result=result*10 +(arr[idx]-'0');
        idx++;
    }

    printf("%d\n",result);
    int count=0;
    for(int i=1;i<=result;i++){
        if(result%i==0){
            //printf("%d ",i);
            count++;
        }
    }
    printf("%d\n",count);


    return 0;
}