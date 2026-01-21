#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string,int> c;
    string answer = "";
    for(string s: participant){
        c[s]++; // 참가자 다 넣어서 이름별 개수 세기
    }
    for(string s : completion){
        c[s]--;
        if(c[s]==0) c.erase(c.find(s)); //만약 다 참여했으면 아웃
    }
    answer=c.begin()->first;
    return answer;
}