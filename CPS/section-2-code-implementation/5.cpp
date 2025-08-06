//05. 나이계산(문자열 컨트롤)
#include <stdio.h>

int main(){
    //freopen("Input.txt","rt",stdin);
    //scanf, printf가 대용량 입출력할 때 더 빠름
    int a,b;
    int age;
    scanf("%d-%d",&a,&b);
    int r=b/1000000;
    int t_age=a/10000;
    int s ='W';
    if(r<=2){
        age=100-t_age+20;
        if(r==1) {
            s='M';
        }        
    }
    else{
        age=20-t_age;
        if(r==3){
            s='M';
        }
    }
    printf("%d %c",age,(char)s);
    return 0;
}

/****************문자열 사용 방안
 * #include<stdio.h>
int main(){
	char a[20];
	int year, age;
	scanf("%s", &a);
	if(a[7]=='1' || a[7]=='2') year=1900+((a[0]-48)*10+(a[1]-48));
	else year=2000+((a[0]-48)*10+(a[1]-48));
	age=2019-year+1;
	printf("%d ", age);
	if(a[7]=='1' || a[7]=='3') printf("M\n");
	else printf("W\n");
	return 0;
}

 */