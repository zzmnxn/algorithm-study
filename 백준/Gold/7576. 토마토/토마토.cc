#include <bits/stdc++.h>

using namespace std;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

vector<vector<int>> result_box;
vector<vector<int>> box;
void bfs(queue<pair<int,int>> q);
int count_days();
int m, n;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>m>>n;
    box = vector<vector<int>> (n, vector<int>(m));//초기 입력값
    result_box= vector<vector<int>>(n, vector<int>(m)); //bfs depth 저장 box
    queue<pair<int,int>> starts;

    for(int i=0;i<n;i++){
        for(int j=0 ; j<m; j++){
            cin>>box[i][j];
            if(box[i][j]==1) starts.push({i,j}); // 초기 start들 저장해두기
        }
    }

    bfs(starts);

    cout<<count_days(); //최종 날짜 

    return 0;
}

void bfs(queue<pair<int,int>> starts){
    queue<pair<int,int>> q;
    while(!starts.empty()){
        auto[a,b]=starts.front();
        starts.pop();
        q.push({a,b});
        result_box[a][b]=1; //start를 1일로 함
    }

    while(!q.empty()){
        auto[a,b] = q.front();
        q.pop();
        int old_depth=result_box[a][b];
        for(int k=0;k<4;k++){
            int ny= a+dy[k];
            int nx = b + dx[k];
            if(ny<0||ny>=n || nx<0 || nx>= m || box[ny][nx]==-1) continue; //경계검사
            if(result_box[ny][nx]>=1) continue; //이미 visited은 pass
            q.push({ny,nx});
            result_box[ny][nx]=old_depth+1; //depth 추가
        }
    }
}

int count_days(){
    int max=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(result_box[i][j]==0 && box[i][j]==0) return -1; //고립된 안 익은 토마토 발견
            if(result_box[i][j]>max){
                max=result_box[i][j]; // bfs 최종 맵에서 가장 큰 값 찾기
            }
        }
    }

    return max-1; //start를 1로 쳤으니 -1 해서 return
}