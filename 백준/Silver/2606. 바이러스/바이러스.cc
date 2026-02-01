#include <bits/stdc++.h>

using namespace std;


vector<int> visited;
vector<vector<int>> computers;
void dfs(int node);
int result;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    computers= vector<vector<int>>(n+1);//1-based
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        computers[a].push_back(b);
        computers[b].push_back(a);
    }
    visited=vector<int> (n+1);
    result=0;
    dfs(1);

    cout<<result;
    return 0;

}

void dfs(int node){
    visited[node]=1;

    for(int a : computers[node]){
        if(visited[a]) continue;
        dfs(a);
        result++;
    }
}