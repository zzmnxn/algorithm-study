#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N, M;

    //N개의 정수 입력받기
    cin>>N>>M;
    vector<int> elec;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        elec.push_back(tmp);
    }

    sort(elec.begin(),elec.end(),greater<>());
    //내림차순으로 정렬
    priority_queue<int, vector<int>, greater<int>> consent;
//min-heap 선언 방법

    for(int i=0;i<M;i++){
        consent.push(0);
    }
    for(int i=0;i<N;i++){
        int tmp= consent.top();
        tmp+=elec[i];
        consent.pop();
        consent.push(tmp);
    }

    int result=0;
    while(!consent.empty()){
        result=consent.top();
        consent.pop();
    }
    cout<<result;
    return 0;
    

    //콘센트의 개수 정해져 있음
    //가장 긴 거랑 동시에 충전해야 총 시간이 적음
    //우선 가장 긴 순으로 sort 함
    // 그러고 가장 긴 것부터 채워 넣음
    // 가장 짧은 거 기준으로 시간 추가하기
    // 시간 다 추가한 거면 빼고 새로운 거 넣기

    //콘센트에 다른 하나가 다 끝날 떄까지는 더 작은 것에 
    // 새로운 거를 추가해야 한다
    //각 콘센트에서 충전하는 총 누적 시간을 계산하는 게 더 빠르지 않을까?
    //따로 외부 변수로 누적 시간을 계산한다는 것은 번거러움
    // 사실 생각을 해보면 각 콘센트 별로 누적 얼마나 충전하고 있는지 count만 해도 됨
    //


    
}