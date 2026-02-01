#include <bits/stdc++.h>

using namespace std;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

vector<vector<int>> visited;
vector<vector<int>> maps;

int bfs(int a, int b);


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    maps = vector<vector<int>>(n);//0-based
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        for(char c : str){
            maps[i].push_back(c-'0');
        }
    }

    visited=vector<vector<int>>(n,vector<int>(n));
    vector<int> result;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]||maps[i][j]==0) continue;
            result.push_back(bfs(i,j));
        }
    }

    cout<<result.size()<<'\n';
    sort(result.begin(), result.end());
    for(int a: result){
        cout<<a<<"\n";
    }

}

int bfs(int a, int b){
    queue<pair<int,int>> q;
    q.push({a,b});
    visited[a][b]=1;
    int r=0;
    while(!q.empty()){
        pair<int,int> cur= q.front();
        q.pop();
        r++;
        for(int i=0;i<4;i++){
            int ny= cur.first+dy[i];
            int nx= cur.second+dx[i];
            if(ny>=maps.size()||ny<0 || nx<0 ||nx>=maps.size()) continue;
            if(visited[ny][nx]|| maps[ny][nx]==0) continue;
            q.push({ny,nx});
            visited[ny][nx]=1;
        }

    }
    return r;

}

