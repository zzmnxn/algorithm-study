#include <stdio.h>
#include <stdlib.h>
    /*Celebrity가 나가는 화살은 없는데
    들어오는 화살은 모두에게 있어야 함.
    이거를 최소 질문으로 해야함
    */
   // 1. celebrity가 있는지 여부
   // 2. 있다면 효율적으로 찾기
// 후보자 제거 알고리즘
#define N 4 // 사람의 수. 실제로는 사용자 입력으로 받거나 동적으로 할당할 수 있습니다.

// 관계 행렬 (adjacency matrix)
// knows_table[i][j] = 1이면 i가 j를 아는 것
int knows_table[N][N] = {
    {0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0}, 
    {0, 0, 1, 0}
};

// a가 b를 아는지 여부를 반환하는 함수 (질문 역할)
int knows(int a, int b) {
    return knows_table[a][b];
}

int main() {

    //초기 후보자 0번으로 설정
    int candidate=0;
    
    for(int i=1;i<N;i++){
        if(knows(candidate,i)){
            //candidate는 i를 알아서 연예인이 될 수 없음
            // i가 새로운 후보
            candidate=i;
        }
        else{
            //i는 연예인이 될 수 없음.
        }
    }

    //후보 검증
    int is_celebrity= 1;

    //candidate 아무도 모르는지, 그리고 모두가 candidate 아는지 확인
    for(int i=0;i<N;i++){
        if(i==candidate) continue;

        if(!knows(i,candidate) || knows(candidate,i)){
            //i가 후보를 모르거나
            //후보가 i를 알거나 하면 연예인 아님
            is_celebrity=0;
            break;
        }
    }

    if(is_celebrity) printf("%d", candidate);
    else printf("-1");

    return 0;


}