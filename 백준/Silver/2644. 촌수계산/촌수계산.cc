#include <iostream>
#include <vector>
#include <queue>
using namespace std;
    int n; // 전체  사람 수
    int a, b; // 계산해야 하는 사람
    int m; // 관계의 개수
vector<vector<int>> people;
 vector<bool> visited;
 int result = -1;

void dfs(int t, int depth){
    visited[t]=true;

    if(t==b){
        result=depth;
        return;
    }

    for(int i=0;i<people[t].size();i++){
        int next= people[t][i];
        if(!visited[next]){
            dfs(next, depth+1);
        }
    }
    
}

int main(){

    cin>>n;
    cin>>a>>b;
    cin>>m;

    people.assign(n+1,vector<int>());
    visited.assign(n+1,false);

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        people[x].push_back(y);
        people[y].push_back(x);
    }
    //어차피 자식에서 부모로 거슬러 올라가야 해서 양방향 연결해줌

    dfs(a,0);
    cout<<result;

    return 0;

}