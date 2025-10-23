#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Edge = pair<int, ll>;

const int MAXN=20005;

int N, K;
vector<Edge> adj[MAXN];
ll dist[MAXN];
int parent[MAXN];
bool on_diameter[MAXN];

vector<int> diameter_path;
vector<ll> diameter_costs;

ll H[MAXN]; //지름 경로상 노드에 연결된 '곁가지'들의 최대 높이
ll S_D[MAXN]; //지름 경로상의 노드에 연결된 '곁가지'들의 최대 지름

ll F_L[MAXN]; // 왼쪽 서브트리에서 v_i로부터 가장 먼 노드까지의 거리
ll D_L[MAXN]; //왼쪽 서브트리의 지름
ll F_R[MAXN]; // 오른쪾 서브트리에서
ll D_R[MAXN];

// u로부터 DFS 수행해서 각 노드까지의 거리와 부모를 저장
void dfs_dist(int u, int p){
    parent[u]=p;
    for(auto& edge : adj[u]){
        int v = edge.first;
        ll cost = edge.second;
        if (v ==p ) continue;
        dist[v] = dist[u] + cost;
        dfs_dist(v,u);
    }
}

// 곁가지 서브트리의 높이, 지름 계산 
pair <ll, ll> dfs_branch(int u, int p){
    ll max_h=0; 
    ll max_d = 0;
    vector<ll> child_heights;
    for(auto& edge: adj[u]){
        int  v= edge.first;
        ll cost = edge.second;
        if(v==p || on_diameter[v]) continue;

        pair<ll, ll> res = dfs_branch(v,u);
        ll h_v = res.first;
        ll d_v= res.second;

        child_heights.push_back(h_v+ cost);
        max_d = max(max_d, d_v);

    }

    sort(child_heights.rbegin(), child_heights.rend());

    if(!child_heights.empty()){
        max_h= child_heights[0];
    }

    if(child_heights.size()>=2){
        max_d=max(max_d, child_heights[0]+ child_heights[1]);
    }

    return {max_h, max_d};
}

int main(void) {
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    //write your code here


    cin>>N>>K;
    for(int i=0;i<N-1;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    fill(dist, dist+N+1,0);
    fill(parent, parent+N+1,0);
    dfs_dist(1,0);

    int A=1;
    for(int i=1;i<=N;i++){
        if(dist[i]>dist[A]){
            A=i;
        }
    }

    fill(dist, dist+N+1,0);
    fill(parent, parent+N+1,0);
    dfs_dist(A,0);

    int B=1;
    for(int i=1;i<=N;i++){
        if(dist[i]>dist[B]){
            B=i;
        }
    }
    ll diameter = dist[B];

    if(K==1){
        cout<<diameter;
        return 0;
    }


    fill(on_diameter, on_diameter+N+1, false);
    int curr= B;
    while(curr!=0){
        diameter_path.push_back(curr);
        on_diameter[curr] = true;
        curr = parent[curr];
    }

    reverse(diameter_path.begin(), diameter_path.end());

    int k = diameter_path.size();

    for (int i = 0; i < k - 1; ++i) {
        int u = diameter_path[i];
        int v = diameter_path[i+1];
        for (auto& edge : adj[u]) {
            if (edge.first == v) {
                diameter_costs.push_back(edge.second);
                break;
            }
        }
    }

    for(int i=0;i<k;i++){
        int u= diameter_path[i];
        vector<ll> branch_heights;
        ll branch_max_d=0;

        for(auto& edge : adj[u]){
            int v= edge.first;
            ll cost = edge.second;
            if(on_diameter[v]) continue;

            pair <ll, ll> res = dfs_branch(v,u);
            branch_heights.push_back(res.first+cost);
            branch_max_d= max(branch_max_d, res.second);
        }

        sort(branch_heights.rbegin(), branch_heights.rend());

        H[u] = (branch_heights.empty() ? 0 : branch_heights[0]);
        
        ll h1_plus_h2 = 0;
        if (branch_heights.size() >= 2) {
            h1_plus_h2 = branch_heights[0] + branch_heights[1];
        }
        S_D[u] = max(branch_max_d, h1_plus_h2);
    }

    int v0 = diameter_path[0];
    F_L[0] = H[v0];
    D_L[0] = S_D[v0];

    for(int i=1;i<k;i++){
        int u = diameter_path[i];
        ll c = diameter_costs[i - 1];

        F_L[i]=max(H[u], F_L[i-1]+c);

       D_L[i] = max({D_L[i - 1], S_D[u], F_L[i - 1] + c + H[u]}); 
    }
    int vk_1 = diameter_path[k - 1];
    F_R[k - 1] = H[vk_1];
    D_R[k - 1] = S_D[vk_1];

    for (int i = k - 2; i >= 0; --i) {
        int u = diameter_path[i];
        ll c= diameter_costs[i];

        F_R[i] = max(H[u], F_R[i + 1] + c);
        D_R[i] = max({D_R[i + 1], S_D[u], F_R[i + 1] + c + H[u]});
    }
    ll min_max_diameter = LLONG_MAX;

    for(int i=0;i<k-1;i++){
        ll diam_A = D_L[i];
        ll diam_B = D_R[i + 1];
        min_max_diameter = min(min_max_diameter, max(diam_A, diam_B));

    }

    cout<< min_max_diameter<<"\n";   

    return 0;
}