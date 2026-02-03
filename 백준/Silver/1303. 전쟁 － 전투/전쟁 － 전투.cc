#include <bits/stdc++.h>


using namespace std;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int w_bfs(int a, int b);
int b_bfs(int a, int b);
vector<vector<int>> visited;
vector<vector<int>> war;
int m,n;

int main(){

    cin>>n>>m;
    war=vector<vector<int>>(m);
    visited=vector<vector<int>>(m,vector<int>(n));
    //W == 2
    // B == 3
    for(int i=0;i<m;i++){
        string str;
        cin>>str;
        for(char c : str){
            if(c=='W') war[i].push_back(2);
            else war[i].push_back(3);
        }
    }
    int wResult=0;
    int bResult=0;

    for(int i=0 ; i<m; i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]!=0) continue;
            if(war[i][j]==2){
                int tmp=w_bfs(i,j);
                wResult+=tmp*tmp;
            }
            else{
                int tmp=b_bfs(i,j);
                bResult+=tmp*tmp;
            }
        }
    }

    cout<<wResult<<" "<<bResult;

    return 0;
}

int w_bfs(int i, int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j]=2;
    int r=0;
    while(!q.empty()){
        pair<int,int> t= q.front();
        q.pop();
        r++;

        for(int i=0;i<4;i++){
            int ny = t.first+ dy[i];
            int nx= t.second + dx[i];

            if(ny<0 || ny>=m || nx<0 || nx>=n ) continue; //범위 검사
            if(war[ny][nx]==3|| visited[ny][nx]==2) continue; //'B'이거나 이미 'W'가 지나간 길이거나
            visited[ny][nx]=2;
            q.push({ny,nx});
        }
    }
    return r;
}


int b_bfs(int i, int j){
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j]=3;
    int r=0;


    while(!q.empty()){
        pair<int,int> t= q.front();
        q.pop();
        r++;

        for(int i=0;i<4;i++){
            int ny = t.first+ dy[i];
            int nx= t.second + dx[i];

            if(ny<0 || ny>=m || nx<0 || nx>=n ) continue; //범위 검사
            if(war[ny][nx]==2|| visited[ny][nx]==3) continue; //'B'이거나 이미 'W'가 지나간 길이거나
            visited[ny][nx]=3;
            q.push({ny,nx});
        }
    }
    return r;
}
