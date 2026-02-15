#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> arr;
int result=0;
void backtracking(int d){
    if(d==N){  //N개의 행에 배치 완료
//경우의 수 1 증가, 함수 반환
        result++;
        return;
    }

    for(int i=0;i<N;i++){ //각 열 탐색
        //i번째 열에 퀸 배치할 수 있으면 배치하기
        bool can_place=true;
        for(int j=0;j<d;j++){
        //세로 공격 방어 : 어차피 위의 행부터 배치해서 같은 행에 배치할 일은 없음
        //가로 공격 방어 : i랑 같은 거 존재시 X
        // 대각선 공격 방어 : index 차이랑 안에 저장된 값 차이랑 같으면 X
            if(arr[j]==i || abs(d-j)==abs(i-arr[j])){
                can_place=false;
               break;
               break;// 한 번이라도 걸리면 더 검사할 필요 없음
            }
        }
        if(can_place){
            arr[d]=i;
            backtracking(d+1);
        }
        //배치 가능하면 d++ 해서 재귀함수 호출
    }
    return;

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    cin>>N;
    arr.assign(N,-1);

    backtracking(0);

    cout<<result;
    return 0;
  
}