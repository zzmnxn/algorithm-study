#include <bits/stdc++.h>

using namespace std;

void dfs(int node);
void bfs(int node);
vector<vector<int>> graph; 
vector<int> visited;



//연결 리스트로도 풀어보기
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,start;
    cin>>n>>m>>start;
    graph.resize(n+1); //1-based;

    for(int i=0;i<m;i++){     
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    for(int i=1;i<n+1;i++){
        sort(graph[i].begin(), graph[i].end());
    }
    visited=vector<int> (n+1);
    
    dfs(start);

    cout<<"\n";
    visited=vector<int> (n+1);
    bfs(start);

    return 0;

}

void dfs(int node){
    visited[node]=1;
    cout<<node<<" ";
    for(int i : graph[node]){
        if(visited[i]) continue;
        dfs(i);
    }
}

void bfs(int node){
    queue<int> q;
    q.push(node);
    visited[node]=1; //queue에 넣을 때 방문 처리!! 

    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        cout<<tmp<<" ";
        for(int a : graph[tmp]){
            if(visited[a]) continue;
            q.push(a);
            visited[a]=true;
        }   
    }
}