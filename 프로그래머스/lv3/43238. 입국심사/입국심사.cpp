#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    // 데이터들이 숫자가 매우 큼 -> 시간복잡도가 짧아야 함 
    //하나하나 배정을 하면서 한다면 시간복잡도가 o(n), Oo(nlogn) 과 같이 나올듯 -> 시간을 찾는 게 핵심
    // 시간의 범위를 구해볼까? -> 이분탐색
    // 문제 : 사람수 주어짐 -> 최소 시간
    // 바꾸어서 어떤 시간 안에 -> 심사 가능한 사람 수는 몇명 ? 구해보기
    // 탐색하는 범위는 어떻게 정할까? 최소는 당연히 1 최대는 가장 오래걸리는 심사관이 모든 사람 다 검사하는 시간
    long long left =1;
  
    long long right = times[times.size()-1]*(long long)n;
    while(left<=right){
        long long people=0;
        long long mid = (left+right)/2;
        for(int i=0;i<times.size();i++){
            people+=mid/times[i];
        }
        if(people<n){
            left=mid+1;
        }else{
            right=mid-1;
            answer=mid;
        }
    }
    
    return answer;
}