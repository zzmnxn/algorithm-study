#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int x=0; int y=0;
    for(int i=0;i<park.size();i++){
        for(int j=0;j<park[i].length();j++){
            if(park[i][j]=='S'){
                y=i;
                x=j;
            }
        }
    }
    int W=park[0].length();
    int H=park.size();
    // 2. 경로 이동 처리
    for(int i = 0; i < routes.size(); i++){
        char dir = routes[i][0];
        int dist = routes[i][2] - '0';

        int nx = x;
        int ny = y;
        bool ok = true;

        // 한 칸씩 이동하며 범위와 장애물('X') 체크
        for(int d = 1; d <= dist; d++){
            if(dir == 'E') nx++;
            else if(dir == 'W') nx--;
            else if(dir == 'S') ny++;
            else if(dir == 'N') ny--;

            // 공원 범위를 벗어나거나 장애물을 만나면 실패
            if(nx < 0 || nx >= W || ny < 0 || ny >= H || park[ny][nx] == 'X'){
                ok = false;
                break;
            }
        }

        // 이동이 모두 가능했을 때만 실제 좌표 반영
        if(ok){
            x = nx;
            y = ny;
        }
    }
    answer.push_back(y);
    answer.push_back(x);
    return answer;
}