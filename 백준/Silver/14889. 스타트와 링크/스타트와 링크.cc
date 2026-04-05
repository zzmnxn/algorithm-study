#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<vector<int>> S;
vector<int> visited;
int result=100000;
int tmp_hap;
int hap=0;
void backtracking(int i, int start);

int main(){

    cin>>n;
    S.resize(n, vector<int>(n));
    visited.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>S[i][j];
            hap+=S[i][j];
        }
    }

    // (1,1)을 뽑으면 1 들어간 거 다 안됨
    //한 줄에서 n/2개만 뽑으면 됨 나머지 팀은 총합에서 뺀 것
    //그러면 뽑았으면 뽑았다고 표시해두기
    // 뽑는 경우의 수는 조합-> 백트래킹으로 풀기 가능
    //다 뽑은 다음에 백트래킹 마지막 단계에서 총 합이랑 차를 result 배열에저장
    // 그 result 배열을 나중에 sort해서 가장 작은 거를 출력

    backtracking(0,0);

    cout<<result;
    
    return 0;

}

void backtracking(int d, int start){
    //d는 몇개 뽑았는지
    //start는 어디까지 뽑았는지
    if(d==n/2){
        vector<int> steam, lteam;
        int s_score=0;
        int l_score=0;

        for(int i=0;i<n;i++){
            //팀 나누기
            if(visited[i]) steam.push_back(i);
            else lteam.push_back(i);
        }
        //다 뽑았음
        
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                //나눈 팀에서 총합 구하기
                s_score += S[steam[i]][steam[j]];
                l_score += S[lteam[i]][lteam[j]];
            }
        }
        int dif= abs(s_score-l_score);
        if(dif<result) result=dif;
        return;
    }

    for(int i=start;i<n;i++){
        if(!visited[i]){
            visited[i]=1;
            backtracking(d+1, i+1);
            visited[i]=0;
        }
    }

}