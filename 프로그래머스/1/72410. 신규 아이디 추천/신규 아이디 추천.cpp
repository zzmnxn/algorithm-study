#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    //첫번째 & 두번째 단계
    for(char c: new_id){
        if(c>='A'&& c<='Z') {
            answer.push_back(c+32);
        }
        else if((c>='a'&&c<='z')|| c=='-' || c =='_' ||c=='.'|| (c>='0'&&c<='9')){
            answer.push_back(c);
        }
        else continue;
    }
    //세번째 단계
    string tmp="";
    int i=0;
    while(i<answer.length()){
        if(answer[i]=='.' && answer[i+1]=='.'){
            i++;
        }else{
            tmp.push_back(answer[i]);
            i++;
        }
    }
    answer=tmp;
    //4단계
    if(tmp[0]=='.'){
        answer=tmp.substr(1);
    }
    if(tmp[tmp.length()-1]=='.'){
        answer=answer.substr(0,answer.length()-1);
    }
    //5단계
    if(answer.empty()){
        answer.push_back('a');
    }
    //6단계
    if(answer.length()>=16) {
        answer=answer.substr(0,15);
        if(answer[14]=='.') answer=answer.substr(0,14);
        
    }
    //7단계
    if(answer.length()<=2){
        int l=answer.length();
        while(l<3){
            answer.push_back(answer[l-1]);
            l++;
        }
    }
    
    return answer;
}