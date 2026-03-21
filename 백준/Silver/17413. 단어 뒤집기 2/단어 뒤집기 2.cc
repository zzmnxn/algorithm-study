#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    
    string s;
    getline(cin, s);

    char result[100001];
    bool isTag=false;
    stack<char> word;
    int idx=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='<') {
             //단어 끝임 -> 집어넣기
             while(!word.empty()){
                result[idx]=word.top();
                word.pop();
                idx++;
             }
             isTag=true;
             result[idx]=s[i];
             idx++;
             continue;
        }
    
        if(s[i]=='>'){
            isTag=false;
            result[idx]=s[i];
            idx++;
            continue;
        }

        if(isTag){
            result[idx]=s[i];
            idx++;
            continue;
        }else{
            if(s[i]==' '){
                while(!word.empty()){
                        result[idx]=word.top();
                    word.pop();
                idx++;
             }
             result[idx++]=s[i]; //공백도 넣어줘야 함!!
            }
            else{
                word.push(s[i]);
            }
        }
        
        //먼저 태그라면 그대로 result에 옮긴다
        // 만약 > 를 만나면 isTag=false로
        //단어가 시작되면
        //단어의 끝 (공백이나 < 만날 때까지)을 기록해두고
        // 중간에는 계속 continue
        // 단어의 끝을 만나면 거기서 시작과 끝 인덱스 활용해서
        //거꾸리 result에 입력
        // 복원 -> stack 자료구조 사용!!

        //기준 판단하는 게 가장 어렵다
        // 크게 나눠보자
        // 1. '<' -> stack에 쌓아둔 거를 꺼내서 넣고 isTag 진입
        // 2. '>' -> isTag 아님 
        // 3. isTag = true : 그냥 result에 넣기
        // 4. isTag= false : 단어일수도 아닐수도
        // -> ' ' -> 단어 끝났으니까 stack에 있는 거 다 꺼내서 result에 추가
        // 공백 아님 -> 단어다~ -> 스택에 넣기

    }
     //마지막이 단어로 끝나면 스택에 저장만해두고 결과에 저장이 안되어 있음
        while(!word.empty()){
            result[idx]=word.top();
            word.pop();
            idx++;
        }

        result[idx]='\0';
        cout<<result<<endl;
        return 0;


}
