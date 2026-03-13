#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct {
    int weight;
    int cross_time;
}Truck;

int main(){
    int n, w, L;
    //트럭 개수 / 다리 길이 / 최대 하중
    cin>>n>>w>>L;

    //트럭 무게 입력 받기
    queue<Truck> trucks;
    for(int i=0;i<n;i++){
        Truck t;
        cin>>t.weight;
        t.cross_time=w;
        trucks.push(t);
    }

    int total_time =0;
    int current_weight=0;
    queue<Truck> bridge;
    Truck f=trucks.front();

    while(!bridge.empty() || !trucks.empty()){
        int l=bridge.size();
        for(int i=0;i<l;i++){
            //bridge는 다리 위의 트럭들 모음
            //다리 위에 있는 트럭들 다 앞으로 한칸씩
            Truck t=bridge.front();
            bridge.pop();
            t.cross_time--; //각각 트럭마다 건너는 시간 체크
            if(t.cross_time==0){ // 다 건넘
                current_weight-=t.weight;
            }
            else{ //아직 다 못 건넘, 다시 줄 안에
                bridge.push(t);
            }
        }
        if(!trucks.empty() && L>=current_weight+trucks.front().weight ){
            //하나 더 추가해도 safe
            current_weight+=trucks.front().weight;
            Truck t = trucks.front();
            trucks.pop();
            bridge.push(t);
        }
        
        total_time++;   

    }
    
    cout<<total_time;
    return 0;



}