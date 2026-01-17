#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

int N;
int a[17], b[17];
ll memo[17][1 << 16];

// index: 현재 숫자를 채워야 할 위치 (0 ~ N-1)
// mask: 현재까지 사용된 숫자들의 비트마스크
ll solve(int index, int mask) {
    // 기저 사례: 모든 위치를 다 채운 경우 1가지 방법 완성
    if (index == N) {
        return 1;
    }

    // 메모이제이션
    if (memo[index][mask] != -1) {
        return memo[index][mask];
    }

    ll res = 0;
    // 현재 위치 index에 숫자 v (1 ~ N)를 놓으려고 시도
    for (int v = 1; v <= N; ++v) {
        int v_bit = 1 << (v - 1);
        
        // 1. 숫자 v가 이미 사용되었는지 확인
        if (!(mask & v_bit)) {
            // 2. 문제 조건: c_i != a_i 이고 c_i != b_i 인지 확인
            if (v != a[index] && v != b[index]) {
                res += solve(index + 1, mask | v_bit);
            }
        }
    }

    return memo[index][mask] = res;
}

void solve_test_case() {
    if (!(cin >> N)) return;
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> b[i];

    // 메모이제이션 배열 초기화
    // N이 최대 16이므로 (1 << 16) 크기면 충분합니다.
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j < (1 << N); ++j) {
            memo[i][j] = -1;
        }
    }

    cout << solve(0, 0) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve_test_case();
    }
    return 0;
}