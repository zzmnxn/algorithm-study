#include <bits/stdc++.h>

using namespace std;

int main(){

    int k; //테스트 케이스 개수
    int v, e; // 정점, 간선

    cin>>k;
    for(int j=0;j<k;j++){
        cin>>v>>e;
        vector<vector<int>> graph(v);  //0-based
        for(int i=0;i<e;i++){// E개의 간선
            int a,b;
            cin>>a>>b;
            graph[a-1].push_back(b-1); //0-based
            graph[b-1].push_back(a-1);
        }

        //이분 그래프 : 
        //모든 정점을 두 개의 그룹으로 나누었을 때, 같은 그룹에 속한 정점끼리는 서로 연결된 간선이 없는 그래프
        //한 정점이 그룹 a일때 그 이웃들은 다 b여야 함.

        vector<int> visited(v,0); //visited 배열  -1이 unvisited;
        bool result=true;
        //visited 배열 1, -1 로 두 그룹을 표현하겠음
        for(int i=0;i<v;i++){//모든 정점을 검사
            if(visited[i]!=0) continue; // 이미 방문 pass
            if(!result) break;
            queue<int> q;
            q.push(i);
            int group= 1; // -로 두 그룹 구분
            visited[i]=group; // 첫 기준이 되는 정점은 1로 시작 
            // 왜 1,-1를 track 안해되 되는가 -> 만약 저번 탐색에서 visited이 아니라면 이미 서로 connected이 아님
            //기준이 되는 정점들 이웃 탐색해서 이웃과 다르게 세팅함
            while(!q.empty()){
                if(!result) break; 
                int t= q.front();
                group=visited[t]; 
                q.pop();
                for(auto a : graph[t]){
                    if(visited[a]== -group) continue; // 이미 방문했고 다른 group에 속한 이웃임
                    if(visited[a]==group) {
                        //이웃이 현재 정점과 같은 그룹임 -> false;
                        result=false;
                        break;
                    }
                    q.push(a);
                    visited[a]=-group; //다른 그룹임을 설정
                }
            }
        }
        
        if(result) cout<<"YES\n";
        else cout<<"NO\n";


    }

}