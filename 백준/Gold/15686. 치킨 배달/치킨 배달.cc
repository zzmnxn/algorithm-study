#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void choosing_chicken(int i,int j);
int m;
vector<vector<int>> idx_choices;
vector<pair<int,int>> chickens;
vector<int> visited; //치킨 배열의 인덱스 저장하는 배열
vector<pair<int,int>> houses;

int calculate_d(vector<int> a);

int main(){

    int n;
    cin>>n>>m; //도시 줄과 최대 치킨집 개수

    //만약 m개와 치킨집 개수가 같으면 최단 치킨 거리 합이 정답
    // 만약 m이 더 작다 그러면 골라야 함 -> 고르는 것을 백트래킹으로 효율적으로
    // 하나 하나 더 해보면서 만약 어떤 조건을 넘는다면 그 위치는 폐기 다음 꺼 탐색
    // 치킨 집의 위치들을 pair로 배열에 집어 넣어서 순번을 매김
    // 그걸 조합하는 형식으로 길이를 하나 하나 세보기
    // 생각해보면 길이를 계산하는 것은 단순 덧셈 뺄셈임. 집의 위치를 이미 알고 있으면 매번 주위를 탐색해서 집을 찾는 것보다
    // 미리 기록한 집의 위치 집단 ( 치킨 집 처럼 pair 배열)과 현재 선택한 치킨 집과의 차이 구해서 더 작은 거 계산해두면 됨
    // 치킨집의 개수는 최대 13개니까 아무리 길어도 13번의 계산만 함. 최대 시간 복잡도는 13* (조합 수) 매우 작음 
    
    //정보 입력받기


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmp;
            cin>>tmp;
            if(tmp == 1) houses.push_back({i,j});
            else if(tmp == 2) chickens.push_back({i,j});
        }
    }

    choosing_chicken(0,0);
    int min=INT_MAX;
    for(int i=0;i<idx_choices.size();i++){
        int new_d=calculate_d(idx_choices[i]);
        if(min>new_d){
            min=new_d;
        }
    }

    cout<<min;


    return 0; 
}

void choosing_chicken(int d, int idx){
    // 치킨집의 위치 인덱스들을 저장한 배열 만드는 함수
    if(d==m){
        idx_choices.push_back(visited); //이 길을 골랐을 때 최단거리 push_back
        return;
    }
    for(int i=idx;i<chickens.size();i++) {//chickens 원소 하나 하나
        visited.push_back(i);
        choosing_chicken(d+1,i+1);
        visited.pop_back();
    }
}

int calculate_d(vector<int> idx_chicks){

    int distance=0;

    for(auto[a,b] : houses){
        int real_d=INT_MAX;
        //각 house 별로 가장 가까운 치킨집 거리 계산
        for(int i : idx_chicks){
            auto[y,x]=chickens[i];
            int new_d=abs(y-a)+abs(x-b);
            if(real_d>new_d) real_d=new_d ;
        }
        distance+=real_d;
    }

    return distance;
}
