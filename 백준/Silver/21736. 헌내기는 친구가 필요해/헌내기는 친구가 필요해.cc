#include <bits/stdc++.h>

using namespace std;


int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};



int main(){
    int n, m;
    cin>>n>>m;
    pair<int,int> start;
    vector<vector<int>> campus(n,vector<int>(m));

    //I = 0
    // X = -1
    // P =1

    for(int i=0;i<n;i++){
        string str;
        cin>>str;

        for(int j=0;j<str.length();j++){
            if(str[j]=='I') {
                start.first=i;
                start.second = j;
                campus[i][j]=0;
            }
            else if(str[j]=='P') campus[i][j]=1;
            else if(str[j]=='X') campus[i][j]=-1;
            else campus[i][j]=0; //빼먹었었음
        }
    }
//논리가 맞다고 생각되면 입력 처리 잘 되는지 확인하기
    vector<vector<int>> visited(n,vector<int>(m,0));
    queue<pair<int,int>> q;
    int result=0;

    q.push({start.first,start.second});
    visited[start.first][start.second]=1;

    while(!q.empty()){
        auto[a,b]=q.front();
        q.pop();
        if(campus[a][b]==1) result++;
        for(int i=0;i<4;i++){
            int ny=a+dy[i];
            int nx= b+ dx[i];
            if(ny<0||nx<0||ny>=n||nx>=m) continue;
            if(visited[ny][nx] || campus[ny][nx]==-1) continue;
            visited[ny][nx]=1;
            q.push({ny,nx});
        }

    }
    if(result) cout<<result;
    else cout<<"TT";

    return 0;


}