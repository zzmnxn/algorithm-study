#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool countCross(vector<int>&stones, int k, int mid){
    int cnt=0;
    for(int s : stones){
        s-=mid-1;
        if(s>0) cnt=0;
        else{
            cnt++;
            if(cnt==k) return false;
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    
    int answer=0;
    int right = 2e8;
    int left=0;
    while(left<=right){
        int mid=(right+left)/2;
        
        if(countCross(stones, k, mid)){
            //mid명 건널 수 있음 더 늘리기
            answer=mid;
            left=mid+1;
        }else{
            right=mid-1;
        }
    }

    return answer;
}