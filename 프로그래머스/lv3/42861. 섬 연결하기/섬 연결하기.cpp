#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int solution(int n, vector<vector<int>> costs) {
    //우선 최소 값을 가지는 다리부터 pick 
    // 그 다리에서 최솟값을 가지는 다리를 또 pick
    //계속 픽하다가 더 이상 픽할 게 없다 그러면 이제 선택 안 된 것들 중에서 최솟값 픽
    // 모든 섬이 픽될때까지 반복
    vector<pair<int,int>> adj[n];
    
    for(vector<int> a : costs){
        adj[a[0]].push_back({a[1],a[2]});
        adj[a[1]].push_back({a[0],a[2]});   
    }
    vector<bool> visited (n,false);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int visited_cnt=0;
    pq.push({0,0});
    int answer = 0;
    
    while(!pq.empty()){
        int dist= pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(visited[cur]) continue; //이미 방문함
        //방문 처리
        visited[cur]=true;
        answer+=dist;
        visited_cnt++;
        
        if(visited_cnt==n) break; //다 했으면 조기 종료 가능
        
        for(auto next : adj[cur]){
            int ni= next.first;
            int nd= next.second;
            
            if(!visited[ni]){
                pq.push({nd,ni});
            }
        }
    }
    
    return answer;
}