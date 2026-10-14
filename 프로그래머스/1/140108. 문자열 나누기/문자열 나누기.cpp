#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 1;
    //가장 처음 꺼를 기준으로 스택에 넣는다. 같으면 스택에 넣는다.
    //다르면 스택에서 꺼낸다.
    //스택이 비었다면 멈추고 끊는다. 그리고 다음 문자를 스택에 넣는다. 
    
    int same_idx=0; 
    int same=0;
    int dif=0;
    for(int i=0;i<s.length();i++){
        if(s[same_idx]==s[i]){
            same++;
        }
        else dif++;
        
        if(same==dif && i<s.length()-1){
            answer++;
            same_idx=i+1;
            same=0;
            dif=0;
        }
    }
    return answer;
}