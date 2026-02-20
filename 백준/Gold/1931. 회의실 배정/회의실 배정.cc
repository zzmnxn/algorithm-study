#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


bool compare1(pair<int,int>& a, pair<int,int>& b){
    if(a.second != b.second) {
        return a.second < b.second; // 빨리 끝나는 순
    }
    return a.first < b.first; // 종료 시간이 같으면 빨리 시작하는 순
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>> meetings;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        meetings.push_back({a,b});
    }

    sort(meetings.begin(), meetings.end(), compare1);

    //회의 끝나는 순으로 정렬하기
    // 다음 회의에서 안 겹치는 회의 고르는 함수 만들기
    //마지막 회의를 골랐을 때 쭉 쭉 안 겹치는 회의 고르기
    //첫번째 회의가 가장 빨리 끝나느 회의가 됨
    // 그러면 이건 무조건 포함해야 됨
    // 인덱스 0부터 쭉 쭉쭉 안 겹치는 회의 고르기
    int count=0;
    int last_end_time = -1; // 마지막으로 선택된 회의의 종료 시간
    for (int i = 0; i < n; i++) {
        // 현재 회의의 시작 시간이 이전 회의의 종료 시간보다 크거나 같다면 선택
        if (meetings[i].first >= last_end_time) {
            count++;
            last_end_time = meetings[i].second; // 종료 시간 업데이트
        }
    }
    cout<< count;

    return 0;
}