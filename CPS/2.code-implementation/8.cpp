//8.올바른 괄호
#include <stdio.h>
#include <stack>

int main(){
    //freopen("input.txt","rt",stdin);
    char input[30];
    scanf("%s",input);
    int idx=1;
    std::stack<int> S;
    S.push(input[0]);
    //stack은 namespace 필요함
    while(input[idx]!='\0'){
        char cur= input[idx];

        //여는 괄호일 떄만 스택에 푸시해야한다.
        if(cur=='('){
            S.push(cur);
        }
        else if(cur==')'){
            if(S.empty()){
                printf("NO");
                return 0;
            }
            if(S.top()=='('){
                S.pop();
            }
            else{
                printf("NO");
                return 0;
            }
        }
        idx++;
    }

    if(S.empty()) {
        printf("YES");
    }
    else printf("NO");

    return 0;

}