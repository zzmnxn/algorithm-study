#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// N은 최대 100,000이므로, 이익의 총합은 10^5 * 10^9 = 10^14로 long long을 사용해야 합니다.
typedef long long ll;

// 미팅 정보를 담는 구조체
struct Meeting {
    ll start;
    ll end;
    ll profit;
    int original_index; // 원래 인덱스 (필수는 아니지만 디버깅에 유용)
};

// 미팅을 종료 시간 (end time) 기준으로 정렬하기 위한 비교 함수
bool compareMeetings(const Meeting& a, const Meeting& b) {
    // 종료 시간이 같은 경우 시작 시간으로 정렬할 필요는 없으나,
    // 일반적으로 안정적인 정렬을 위해 추가할 수 있습니다.
    if (a.end != b.end) {
        return a.end < b.end;
    }
    return a.start < b.start;
}

/**
 * 이진 탐색을 사용하여 미팅 M_i와 겹치지 않는 가장 늦게 끝나는 미팅의 인덱스를 찾습니다.
 * 즉, e_j <= s_i 를 만족하는 가장 큰 인덱스 j를 찾습니다.
 *
 * @param meetings 정렬된 미팅 목록 (종료 시간 기준)
 * @param i 현재 미팅의 인덱스
 * @return 겹치지 않는 가장 늦은 미팅의 인덱스 j (0-based).
 * 만약 그런 미팅이 없으면 -1을 반환합니다.
 */
int findLatestNonOverlapping(const vector<Meeting>& meetings, int i) {
    ll target_start_time = meetings[i].start;
    int low = 0;
    int high = i - 1;
    int latest_j = -1; // 겹치지 않는 가장 늦은 미팅의 인덱스

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // 현재 미팅 (i)의 시작 시간보다 작거나 같은 종료 시간을 갖는 미팅 (mid)을 찾습니다.
        // 문제 조건: 미팅이 겹치는 경우만 제외함. E=S는 허용.
        if (meetings[mid].end <= target_start_time) {
            // 조건을 만족합니다. 이 미팅은 선택 가능합니다.
            // 더 늦게 끝나는 미팅을 찾기 위해 오른쪽으로 이동합니다.
            latest_j = mid;
            low = mid + 1;
        } else {
            // 조건을 만족하지 않습니다 (겹칩니다). 더 일찍 끝나는 미팅을 찾아야 합니다.
            high = mid - 1;
        }
    }
    return latest_j;
}

void solve() {
    int N;
    if (!(cin >> N)) return;

    vector<Meeting> meetings(N);
    for (int i = 0; i < N; ++i) {
        cin >> meetings[i].start >> meetings[i].end >> meetings[i].profit;
        meetings[i].original_index = i;
    }

    // 1. 미팅을 종료 시간 기준으로 오름차순 정렬
    sort(meetings.begin(), meetings.end(), compareMeetings);  //syntax 암기!!! .begin(), . end(, compare 뭐시기)
    
    // DP 배열 정의: DP[i] = 정렬된 미팅 목록에서 M_i까지 고려했을 때의 최대 이익
    // DP[0]는 사용하지 않습니다. (1-based index처럼 사용)
    // 크기는 N+1로 설정하고 0부터 N-1 인덱스를 사용하도록 조정하거나,
    // N 크기로 설정하고 0부터 N-1 인덱스를 사용합니다.
    vector<ll> dp(N);

    // 2. DP 계산 시작
    for (int i = 0; i < N; ++i) {
        ll current_profit = meetings[i].profit;
        
        // A. 미팅 M_i를 선택하지 않는 경우: 이전 최대 이익을 가져옵니다.
        ll profit_exclude = (i > 0) ? dp[i - 1] : 0;
        
        // B. 미팅 M_i를 선택하는 경우:
        //    M_i와 겹치지 않는 가장 늦은 미팅 j를 찾습니다.
        int j = findLatestNonOverlapping(meetings, i);
        
        ll profit_include = 0;
        if (j != -1) {
            // M_j까지의 최대 이익 (dp[j])에 현재 미팅의 이익을 더합니다.
            profit_include = dp[j] + current_profit;
        } else {
            // 겹치지 않는 미팅이 없는 경우 (M_i가 첫 미팅인 경우)
            profit_include = current_profit;
        }

        // C. 두 경우 중 최대값을 선택하여 dp[i]에 저장합니다.
        dp[i] = max(profit_exclude, profit_include);
    }

    // 3. 최종 결과: 정렬된 미팅 목록의 마지막까지 고려했을 때의 최대 이익
    cout << dp[N - 1] << "\n";
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 테스트 케이스가 하나만 주어진 것으로 가정 (문제에서 T에 대한 언급이 없으므로)
    solve();

    return 0;
}