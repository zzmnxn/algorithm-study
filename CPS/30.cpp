/*********30. 3의 개수는?(large)******/
//구글 인터뷰 
//입력이 매우 큰 숫자
#include <stdio.h>

int main(){
    //freopen("Input.txt","rt",stdin);
    int lt, cur, rt, k;
    //k : 현재 자리 수
    lt=-1;
    k=1;
    int n;
    scanf("%d",&n);
    int result=0;
    while(lt!=0){
        lt=n/(k*10);
        cur=(n/k)%10;
        rt=n%k;
        
        if(cur==3){
            result+=(lt*k)+rt+1;
        }
        else if(cur>3){
            result+=(lt+1)*k;
        }
        else result+=(lt*k);
        k*=10;
    }
    printf("%d",result);
    return 0;

}
/***********
 * 각 자리에서 3이 얼마나 등장하느냐 수학적으로 think
 * 
 */