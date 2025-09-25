// #include <iostream>
// #include <vector>
// #include <numeric>
// #include <algorithm>
// #include <map>

// // 각 턴의 카드 세트를 저장하기 위한 구조체
// struct TurnCards {
//     long long cardA, cardB, cardC;
// };

// // isBobWin DP 테이블에서 특정 상태의 값을 안전하게 조회하는 함수
// // 키가 존재하지 않으면 false를 반환 (Bob의 필승 상태가 아님)
// bool checkWinState(const std::map<long long, bool>& layer, long long sum) {
//     auto it = layer.find(sum);
//     if (it != layer.end()) {
//         return it->second;
//     }
//     return false;
// }

// int main() {
//     // C++ 입출력 속도 향상
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(nullptr);

//     int N; // 총 턴 수
//     long long L, R; // 목표 점수 구간
//     std::cin >> N >> L >> R;

//     std::vector<TurnCards> turns(N);
//     for (int i = 0; i < N; ++i) {
//         std::cin >> turns[i].cardA >> turns[i].cardB >> turns[i].cardC;
//     }

//     // --- 1단계: '밥의 필승 지도' 완성 ---
//     std::vector<long long> futureMinGain(N + 1, 0);
//     std::vector<long long> futureMaxGain(N + 1, 0);

//     for (int i = N - 1; i >= 0; --i) {
//         futureMinGain[i] = futureMinGain[i + 1] + turns[i].cardA;
//         futureMaxGain[i] = futureMaxGain[i + 1] + turns[i].cardC;
//     }

//     std::vector<std::map<long long, bool>> isBobWin(N + 2);

//     for (long long s = L; s <= R; ++s) {
//         isBobWin[N + 1][s] = true;
//     }

//     for (int i = N; i >= 1; --i) {
//         long long lower_bound = L - futureMaxGain[i];
//         long long upper_bound = R - futureMinGain[i];

//         for (long long s = lower_bound; s <= upper_bound; ++s) {
//             int winnableFutures = 0;
//             const auto& nextLayer = isBobWin[i + 1];
//             if (checkWinState(nextLayer, s + turns[i - 1].cardA)) winnableFutures++;
//             if (checkWinState(nextLayer, s + turns[i - 1].cardB)) winnableFutures++;
//             if (checkWinState(nextLayer, s + turns[i - 1].cardC)) winnableFutures++;
//             if (winnableFutures >= 2) {
//                 isBobWin[i][s] = true;
//             }
//         }
//     }

//     // --- 최종 판정 및 전략 탐색 ---
//     if (checkWinState(isBobWin[1], 0)) {
//         // 1턴, 합 0이 Bob의 필승 상태이므로 Bob이 이김
//         std::cout << "Bob" << std::endl;
//     } else {
//         // Alice가 이기는 경우, 전략을 출력
//         std::cout << "Alice" << std::endl;
        
//         long long currentSum = 0;
//         // --- 2단계: 앨리스의 최적 경로 탐색 ---
//         for (int i = 1; i <= N; ++i) {
//             const auto& nextLayer = isBobWin[i + 1];
//             const auto& currentTurnCards = turns[i - 1];

//             // 시나리오 1: Alice가 A를 금지할 경우
//             // Bob에게 남는 B, C가 모두 Bob의 패배로 이어지는지 확인
//             bool banA_is_safe = !checkWinState(nextLayer, currentSum + currentTurnCards.cardB) &&
//                                 !checkWinState(nextLayer, currentSum + currentTurnCards.cardC);
//             if (banA_is_safe) {
//                 std::cout << "Ban " << currentTurnCards.cardA << std::endl;
//                 // Bob은 남은 카드 중 작은 것을 선택한다고 가정하여 합계 업데이트
//                 currentSum += currentTurnCards.cardB;
//                 continue;
//             }

//             // 시나리오 2: Alice가 B를 금지할 경우
//             bool banB_is_safe = !checkWinState(nextLayer, currentSum + currentTurnCards.cardA) &&
//                                 !checkWinState(nextLayer, currentSum + currentTurnCards.cardC);
//             if (banB_is_safe) {
//                 std::cout << "Ban " << currentTurnCards.cardB << std::endl;
//                 currentSum += currentTurnCards.cardA;
//                 continue;
//             }

//             // 시나리오 3: Alice가 C를 금지할 경우
//             // (Alice가 이기는 게임에서는 위 세 시나리오 중 하나는 반드시 참임)
//             std::cout << "Ban " << currentTurnCards.cardC << std::endl;
//             currentSum += currentTurnCards.cardA;
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
long long N, L, R, arr[40005][3];

// 4개의 함수의 "함수 원형(인자/반환형/이름)"은 절대 바꾸면 안됩니다.
// 전역 변수/함수/클래스 정의 등은 자유롭게 수정하거나 추가해도 됩니다.
// 정답을 최종 제출할 때 I/O(입출력)는 진행하면 안됩니다. 채점기는 이 4개의 함수만 호출하며 I/O는 엄격히 금지합니다.
// 디버그, 테스트 목적의 출력은 허용됩니다. (e.g. printf, cout)
// I/O를 조작하여 부당한 점수를 얻은 경우, 향후 재채점에서 0점 처리됩니다.

//DP 테이블 i 턴 시작 시 Bob이 이낄 수 있는 합계의 구간들 저장
vector<vector<pair<long long, long long>>> BobWinIntervals;

vector<pair<long long, long long>> intersect(const vector<pair<long long, long long>>& A, const vector<pair<long long, long long>>& B){
    vector<pair<long long, long long>> result;
    int i=0, j=0;
    while(i<A.size() && j <B.size()){
        long long start = max(A[i].first, B[j].first);
        long long end = min(A[i].second,B[j].second);

        if(start<=end){
            result.push_back({start,end});
        }

        if(A[i].second < B[j].second){
            i++;
        }else{
            j++;
        }
    }
    return result;
}

vector<pair<long long, long long>> union_i ( const vector<pair<long long, long long>>& A, const vector<pair<long long, long long>>& B){
    vector<pair<long long, long long>> merged;
    int i=0, j=0;
    while(i<A.size() || j<B.size()){
        if(i<A.size() && (j== B.size() || A[i]<B[j])){
            merged.push_back(A[i++]);
        }else{
            merged.push_back(B[j++]);
        }
    }

    if(merged.empty()){
        return {};
    }
    vector<pair<long long, long long>> result;
    result.push_back(merged[0]);

    for(size_t k= 1; k<merged.size(); ++k){
        if(merged[k].first<=result.back().second+1){
            result.back().second= max(result.back().second, merged[k].second);
        }
        else{
            result.push_back(merged[k]);
        }
    }
    return result;
}


bool need_debug() {

    // 이 함수는 딱 한번 호출됩니다.
    // 실제 게임이 어떻게 되었는지 확인하고 싶으면 true를 return하면 됩니다. 이외에는 false를 return하면 됩니다.
    // true를 return해도 채점이 되긴 하지만, 정답을 최종 제출할 땐 false를 return하는 상태로 제출하는것을 권장합니다.

    // return false; // 정답을 제출할 때에는 false로 바꿔주세요.
    return false;
    
}

void alice_init(long long n, long long l, long long r, const std::vector<std::vector<long long>>& v) {
    
    N = n, L = l, R = r;
    BobWinIntervals.assign(N + 1, vector<pair<long long, long long>>());
    BobWinIntervals[N].push_back({L,R}); 
    //N턴 후에 [L,R] 구간에 Bob 있으면 승리

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) arr[i][j] = v[i][j];
    }

    for(int i=N-1; i>=0; --i){
        long long cardA = v[i][0];
        long long cardB = v[i][1];
        long long cardC= v[i][2];

        const auto& next_intervals = BobWinIntervals[i+1];

        //i +! 턴의 승리 구간들로부터 i턴의 승리 후보 구간들 계산
        vector<pair <long long, long long>> i_A, i_B, i_C;
        for(const auto&p : next_intervals){
            i_A.push_back({p.first-cardA, p.second - cardA});
            i_B.push_back({p.first-cardB, p.second - cardB});
            i_C.push_back({p.first-cardC, p.second - cardC});
        }

        // 3개의 후보 중 2 개 이상 포함되는 구간 찾기
        auto AB=intersect(i_A, i_B);
        auto AC= intersect(i_A, i_C);
        auto BC= intersect(i_B, i_C);

        auto AB_AC= union_i(AB, AC);
        BobWinIntervals[i]= union_i(AB_AC, BC);
    }

    // 이 함수는 딱 한번 호출됩니다. 
    // 여기서 입력을 보관하고, 필요한 무거운 연산들인 전처리/사전 계산 등을 모두 끝내야 합니다.
    // 이후 alice_ban()를 반복적으로 실행할 때, 충분히 빠르게 동작해야 합니다.
    // 총 수행시간 중 채점기와 Bob의 코드의 총 수행시간은 5초 미만임을 보장합니다.
    // 즉 alice_init, is_alice_win을 한번 실행하고 alice_ban을 N번 실행하는 시간의 총 합은 15초 미만이어야 합니다.

}

bool is_Bob_win(long long turn, long long S) {

    // 이 함수는 alice_init 이후에 딱 한번 호출됩니다. 
    // 앨리스가 승리할 수 있으면 true, 아니면 false를 return해야 합니다.
    // 정답과 다른 값을 return하면 오답으로 판정됩니다.
    const auto& intervals = BobWinIntervals[turn];
    if(intervals.empty()) return false;

    auto it =lower_bound(intervals.begin(), intervals.end(), make_pair(S,S));

    if(it!= intervals.end() && it->first <= S && S<= it->second){
        return true;
    }

    if(it!=intervals.begin()){
        --it;
        if(it->first<=S && S<= it->second){
            return true;
        }
    }

    return false;

}

bool is_alice_win(){
    return !is_Bob_win(0,0);
}

int alice_ban(int turn, long long S) { //turn은 0-base로 들어옵니다.

    // is_alice_win()에서 true를 return하면 호출되는 함수이며, 정확히 N번 호출되는 함수입니다.
    // 매 호출시 현재 진행중인 턴수와 S값이 주어집니다. 이번 턴에 앨리스가 밴할 인덱스를 return해야 합니다.
    // main함수에서는 alice_ban과 bob_pick함수가 서로 번갈아가면서 실행됩니다. 
    // turn은 0-base로 들어옵니다. 즉 turn = [0..N-1]이 순차적으로 들어옵니다.
    // 즉 현재 밴한 결과는 다음 bob_pick 함수 호출때 영향을 미치며 다음 alice_ban 함수에도 연쇄적으로 영향을 끼칩니다.
    // indx는 0-base입니다. 즉 [0..2]사이의 int를 return해야합니다.
    // 그 외의 값을 return할 시 채점 결과는 오답으로 판정되고 프로그램을 즉시 종료합니다.
    // 최종 S값이 [L..R]사이에 들어오면 오답으로 판정됩니다, 들어오지 않는다면 정답으로 판정됩니다.

    long long A = arr[turn][0];
    long long B= arr[turn][1];
    long long C= arr[turn][2];

    if(!is_Bob_win(turn+1, S+B) && !is_Bob_win(turn+1, S+C)){
        return 0;
    }
    if(!is_Bob_win(turn+1, S+A) && !is_Bob_win(turn+1, S+C)){
        return 1;
    }
    return 2;

}