#include <string>
#include <vector>
#include <queue> //왜 꼭 queue여야 하는지 생각
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> q;
    queue<int> s;
    //progresses가 줄어들면 speeds도 줄어듦 -> 반복횟수 매번 다름
    // 한 번의 순회는 speeds의 개수만큼
    vector<int> answer;
    for(int i=0;i<progresses.size();i++){
        q.push(progresses[i]);
        s.push(speeds[i]);
    }
    int num;
    while(!q.empty()){
        num=0;
        int l=s.size();
        for(int j=0;j<l;j++){
            int spe= s.front();
            int tmp=q.front()+=spe;
            q.pop();
            s.pop();
            q.push(tmp);
            s.push(spe);
        }
        for(int j=0;j<l;j++){
        int t= q.front();
        if(t>=100){
            q.pop();
            s.pop();
            num++;
        }
        }
        if(num == 0) continue;
        answer.push_back(num);        
    }
    return answer;
}