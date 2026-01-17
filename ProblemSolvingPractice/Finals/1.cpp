#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int r, g,b;
    //두 색상이 같은지 비교하는 연산자 오버로딩

}color;

bool operator==(const color& left, const color& right) {
    return left.r == right.r && left.g == right.g && left.b == right.b;
}

const int dx[] = {-1, 1, 0,0,-1,-1,1,1};
const int dy[] = {0,0, -1,1,-1,1,-1,1};

int N, M;
vector<vector<color>> image;
vector<vector<bool>> visited;

void bfs(int startX, int startY){
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY]=true;

    color target_color= image[startX][startY];

    while(!q.empty()){
        pair<int,int> current = q.front(); //q 맨 앞에 있는 거 보이기
        q.pop(); // 반환값 없음 주의
        int x = current.first;
        int y = current.second;

        for(int i= 0 ;i< 8 ;i++){
            int nx= x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && nx<N && ny>=0 &&ny<M){
                if(!visited[nx][ny]){
                    if(image[nx][ny]==target_color){
                        visited[nx][ny]=true;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    image.resize(N, vector<color>(M));
    visited.resize(N, vector<bool>(M,false));

    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> image[i][j].r >> image[i][j].g >> image[i][j].b;
        }
    }

    int obj_count = 0;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!visited[i][j]){
                obj_count++;
                bfs(i,j);
            }
        }
    }
    cout<<obj_count<<endl;



    return 0;

}