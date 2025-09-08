#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<string> adj(n);
    for(int i=0; i<n;i++){
        cin>>adj[i];
    }

    int maxCount=0;

    for(int start=0;start<n;start++){
        vector<bool> visited(n,false);
        queue<pair<int,int>> q; //(노드, 거리)

        visited[start]=true;
        q.push({start,0});

        while(!q.empty()){
            auto[cur, dist]=q.front();
            q.pop();

            if(dist==2) continue;
            for(int next=0;next<n;next++){
                if(adj[cur][next]=='Y' && !visited[next]){
                    visited[next]=true;
                    q.push({next,dist+1});
                }
            }
        }
        visited[start]=false; //자기 자신 제외
        int cnt= count(visited.begin(), visited.end(), true);
        maxCount= max(maxCount, cnt);
    }

    cout<<maxCount;
}
