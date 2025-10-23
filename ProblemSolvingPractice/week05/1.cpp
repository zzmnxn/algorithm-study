#include <bits/stdc++.h>
using namespace std;

//bfs : start_node에서 시작하여 max_dist까지만 탐색
void pruned_bfs(int start_node, int max_dist, int n, const vector<vector<int>> & adj, vector<int>& dist){
    fill(dist.begin(), dist.end(), -1);

    queue<pair<int,int>> q;

    q.push({start_node,0});
    dist[start_node]=0;

    while(!q.empty()){
        auto [u,d]= q.front();
        q.pop();

        if(d>=max_dist) continue;

    for(int v : adj[u]){
        if (dist[v]==-1){
            int next_dist = d+1;
            dist[v]=next_dist;
            q.push({v, next_dist});
        }
    }
    }
}


int main(void) {
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //정보 입력 // red vertex
    vector<pair<int, int>> red_vertices;
    for(int i=1;i<=n;i++){
        int d;
        cin>>d;
        if(d!=-1){
            red_vertices.push_back({d,i});
        }
    }

    //k=0 예외 처리
    if(red_vertices.empty()){
        cout<<n<<"\n";
        for(int i=1;i<=n;i++){
            cout<<i<< (i==n ? "" : " ");
        }
        return 0;
    }

    //d_i가 클수록 후보군 작을 것이라는 추측
    sort(red_vertices.rbegin(), red_vertices.rend());  //역방향 iterator 이용
    unordered_set<int> candidates;
    int r0= red_vertices[0].second;
    int d0= red_vertices[0].first;

    vector<int> disti(n+1);

    pruned_bfs(r0, d0, n, adj, disti);

    for(int v=1; v<=n;v++){
        if(disti[v]==d0){
            candidates.insert(v);
        }
    }

    for(int i=1;i<red_vertices.size();i++){
        if(candidates.empty()) break;

        int r_i =red_vertices[i].second;
        int d_i= red_vertices[i].first;

        pruned_bfs(r_i,d_i,n, adj, disti);

        unordered_set<int> next_cand;

        for(int v: candidates){
            if(disti[v]==d_i){
                next_cand.insert(v);
            }
        }

        candidates=next_cand;
    }

    cout<< candidates.size()<<"\n";

    if(!candidates.empty()){
        vector<int> final_answer;
        for(int v: candidates){
            final_answer.push_back(v);
        }

        sort(final_answer.begin(), final_answer.end());

        for(int v : final_answer){
            cout<<v<<" ";
        }
    }

    return 0;
}