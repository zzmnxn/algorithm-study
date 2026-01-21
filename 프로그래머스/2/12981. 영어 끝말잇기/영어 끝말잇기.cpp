#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_set<string> used;

    used.insert(words[0]);
    answer.push_back(0);
    answer.push_back(0);
    int idx=-1;
    //if(words[0].length() == 1) idx=0;
    for(int i=1; i< words.size();i++){
        if(used.count(words[i]) || words[i].length()==1) {
            idx=i;
            break;
        }
        if(words[i-1][words[i-1].length()-1]!=words[i][0]){
            idx=i;
            break;
        }     
        used.insert(words[i]);
    }
    if(words[0].length() == 1) idx=0;
    if(idx!= -1){
    answer[0]=(idx)%n+1; // 인덱스 계산 손으로 쓰기
    answer[1]=(idx)/n+1;
    }
    return answer;
}