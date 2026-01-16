#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(const pair<double,int>& a, const pair<double,int>& b){
    if(a.first == b.first) return a.second < b.second;
    return a.first> b.first;
    
}

vector<int> solution(int N, vector<int> stages) {
    //우선 각 스테이지에 멈춰있는 사람들의 수를 구해야함
    //실패율 = 현재 스테이지에 멈춰있는 사람 수 / 가장 높은 스테이지부터 멈춰있는 사람들의 합
    // grades (N+1) 선언

    vector<int> grades(N+2); //각 스테이지별 멈춰있는 사람 수
    for(auto s : stages){
        grades[s]++;  // stages 순회하면서 grades[stages[i]] ++해줌
        // 1~N+1까지 사람 존재
        //1-based
    }
    int hap=grades[N+1]; 
    vector<pair<double,int>> fails(N+1);  //(0,0)으로 초기화 1-based
    // 실패율 저장할 fails (N+1) & 누적합 저장할 hap 으로 뒤부터 계산
    //sort 한다고 해도 그게 몇 번째 스테이지인지 알아야 함
    //pair 활용
    for(int i=0; i<N+1;i++){
        fails[i].second=i; //인덱스 초기화 1-based
    }
    for(int i=N;i>0;i--){
        hap+=grades[i];  //N번째 스테이지 실패율 = (N번째 스테이지 사람 수)/(N번째 +N+1번째)
        if(hap==0) { // 0 division 주의
            fails[i].first = 0;
            continue; 
        }
        fails[i].first=(double)grades[i]/hap; //double 자료형 실수 주의
        
    }
    sort(fails.begin()+1,fails.end(),compare);
    
    vector<int> answer;
    for(int j=1;j<=N;j++){
        answer.push_back(fails[j].second);
    }
    return answer;
}