#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    // 3가지 연산 가능
    // 양방향으로 pop 가능하니까 덱 사용
    // 1. pop_front()
    // 2. pop_front(), push_back()
    // 3. pop_back(), push_front()

    // 2 번이나 3 번 연산의 최솟값을 출력하기!

    //큐의 크기 , 뽑아내려고 하는 수의 개수
    int N, M; 
    cin>>N>>M;
    queue<int> find;

    for(int i=0;i<M;i++){
        int tmp;
        cin>>tmp;
        find.push(tmp);
    }

    //덱 증가하는 숫자로 채우기
    deque<int> nums;
    for(int i=1;i<=N;i++){
        nums.push_back(i);
    }

    int result=0; // 2번 , 3번 연산 수

    while(!find.empty()){
        int idx=0;
        for(int i=0;i<nums.size();i++){
            if(find.front()==nums[i]){
                idx=i;
                break;
            }
        }
        
        int l=nums.size();
        if(idx>l/2){
            //여기서 >= 등호를 쓰면 안됨
            // 왜냐면 2번이 좀 더 효율적이기 때문에?
            // 자세한 설명
            for(int i=0;i<l-idx;i++){
                result++;
                int tmp= nums.back();
                nums.pop_back();
                nums.push_front(tmp);
            }
        }
        else{
            for(int i=0;i<idx;i++){
                result++;
                int tmp=nums.front();
                nums.pop_front();
                nums.push_back(tmp);
            }
        }

        nums.pop_front();
        find.pop();
    }

    cout<<result;
    return 0;


    //그러면 "최소"로 구하려면 어떻게 하는걸까
    // 뽑으려고 하는 숫자의 인덱스가 현재 size/2 보다 크다면 뒤에부터
    //-> 현재 목표 숫자의 인덱스는 어떻게 구하지?
    // queue와 달리 deque는 중간 인덱스 접근 가능
    // 아니라면 앞에부터
    // 계속 돌아가는 큐임
    //뽑아내는 건 1번 연산으로 밖에 안됨 -> 맨 처음으로 이동시켜야 함

    // 10에서 2를 뽑으려면
    // 2번 연산, 1번 연산
    // 3 4 5 6 7 8 9 10 1
    // 10 1 3 4 5 6 7 8
    


    
}