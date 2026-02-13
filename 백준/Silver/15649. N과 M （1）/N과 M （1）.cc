#include <iostream>
#include <vector>


using namespace std;

void backtracking(int n);

vector<int> visited;
vector<int> result;
int m,n;

int main(){
    cin>>n>>m;
    result.assign(m,0);
    visited.assign(n+1, false);
    //1부터 n까지 자연수 중
    // 중복없이 m개를 고른 수열

    //전체 구해야 하는 개수를 미리 계산해서? 그러면 백트래킹 아닌 거 같아
    // 탐색하면서 아닌 걸 쳐내자

    //처음에 1 선택 후 재귀 들어감
    // 재귀에서 선택 했다면 return 아니라면 선택한 거 재귀 또 들어감
    // 다 선택했으면 다시 return
    // 그렇다면 재귀에서 넘겨주어야 할 것은 뭘까? -> 그 재귀로 인한 진행사항을 체크
    // 그러면 배열을 넘겨주기? 
    // 뭘 담은 배열? m 길이여야 함

    // 핵심 구성요소는 3가지
    // 1. result 배열(현재까지 내가 선택한 숫자들 : m)
    // 2. visited 배열 ( 이미 사용한지 체크 n+1)
    // 3. depth : 지금까지 몇개의 숫자를 골랐지? 깊이

    backtracking(0);



}


void backtracking(int l){
    if(l==m){
        for(int i=0;i<m;i++){
            cout<<result[i]<<" ";
            
        }
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            visited[i]=1;
            result[l]=i;
            backtracking(l+1);
            visited[i]=0;
        }
    }

}