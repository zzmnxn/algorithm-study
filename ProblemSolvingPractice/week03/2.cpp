#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

// 각 턴의 카드 세트를 저장하기 위한 구조체
struct TurnCards {
    long long cardA, cardB, cardC;
};

// isBobWin DP 테이블에서 특정 상태의 값을 안전하게 조회하는 함수
// 키가 존재하지 않으면 false를 반환 (Bob의 필승 상태가 아님)
bool checkWinState(const std::map<long long, bool>& layer, long long sum) {
    auto it = layer.find(sum);
    if (it != layer.end()) {
        return it->second;
    }
    return false;
}

int main() {
    // C++ 입출력 속도 향상
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N; // 총 턴 수
    long long L, R; // 목표 점수 구간
    std::cin >> N >> L >> R;

    std::vector<TurnCards> turns(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> turns[i].cardA >> turns[i].cardB >> turns[i].cardC;
    }

    // --- 1단계: '밥의 필승 지도' 완성 ---
    std::vector<long long> futureMinGain(N + 1, 0);
    std::vector<long long> futureMaxGain(N + 1, 0);

    for (int i = N - 1; i >= 0; --i) {
        futureMinGain[i] = futureMinGain[i + 1] + turns[i].cardA;
        futureMaxGain[i] = futureMaxGain[i + 1] + turns[i].cardC;
    }

    std::vector<std::map<long long, bool>> isBobWin(N + 2);

    for (long long s = L; s <= R; ++s) {
        isBobWin[N + 1][s] = true;
    }

    for (int i = N; i >= 1; --i) {
        long long lower_bound = L - futureMaxGain[i];
        long long upper_bound = R - futureMinGain[i];

        for (long long s = lower_bound; s <= upper_bound; ++s) {
            int winnableFutures = 0;
            const auto& nextLayer = isBobWin[i + 1];
            if (checkWinState(nextLayer, s + turns[i - 1].cardA)) winnableFutures++;
            if (checkWinState(nextLayer, s + turns[i - 1].cardB)) winnableFutures++;
            if (checkWinState(nextLayer, s + turns[i - 1].cardC)) winnableFutures++;
            if (winnableFutures >= 2) {
                isBobWin[i][s] = true;
            }
        }
    }

    // --- 최종 판정 및 전략 탐색 ---
    if (checkWinState(isBobWin[1], 0)) {
        // 1턴, 합 0이 Bob의 필승 상태이므로 Bob이 이김
        std::cout << "Bob" << std::endl;
    } else {
        // Alice가 이기는 경우, 전략을 출력
        std::cout << "Alice" << std::endl;
        
        long long currentSum = 0;
        // --- 2단계: 앨리스의 최적 경로 탐색 ---
        for (int i = 1; i <= N; ++i) {
            const auto& nextLayer = isBobWin[i + 1];
            const auto& currentTurnCards = turns[i - 1];

            // 시나리오 1: Alice가 A를 금지할 경우
            // Bob에게 남는 B, C가 모두 Bob의 패배로 이어지는지 확인
            bool banA_is_safe = !checkWinState(nextLayer, currentSum + currentTurnCards.cardB) &&
                                !checkWinState(nextLayer, currentSum + currentTurnCards.cardC);
            if (banA_is_safe) {
                std::cout << "Ban " << currentTurnCards.cardA << std::endl;
                // Bob은 남은 카드 중 작은 것을 선택한다고 가정하여 합계 업데이트
                currentSum += currentTurnCards.cardB;
                continue;
            }

            // 시나리오 2: Alice가 B를 금지할 경우
            bool banB_is_safe = !checkWinState(nextLayer, currentSum + currentTurnCards.cardA) &&
                                !checkWinState(nextLayer, currentSum + currentTurnCards.cardC);
            if (banB_is_safe) {
                std::cout << "Ban " << currentTurnCards.cardB << std::endl;
                currentSum += currentTurnCards.cardA;
                continue;
            }

            // 시나리오 3: Alice가 C를 금지할 경우
            // (Alice가 이기는 게임에서는 위 세 시나리오 중 하나는 반드시 참임)
            std::cout << "Ban " << currentTurnCards.cardC << std::endl;
            currentSum += currentTurnCards.cardA;
        }
    }

    return 0;
}
