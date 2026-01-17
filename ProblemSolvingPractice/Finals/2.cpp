#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
  
    // 헬퍼 함수: A의 [r1, r2] 행, [c1, c2] 열의 합을 O(1)에 계산
    // r1, c1, r2, c2는 0-based index (A의 인덱스)
    //참조로 넘겨줘서 효율성 챙기기 const는 그냥 안전상
ll calculate_sum(const vector<vector<ll>>& P, int r1, int c1, int r2, int c2) {
    return P[r2 + 1][c2 + 1] 
         - P[r1][c2 + 1] 
         - P[r2 + 1][c1] 
         + P[r1][c1];
}

void solve() {
    // 1. 입력 및 배열 초기화
    int N, M, K, S;
    if (!(cin >> N >> M >> K >> S)) return;

    // A 배열은 0-based indexing (크기 N x M)
    vector<vector<ll>> A(N, vector<ll>(M)); 
    // P 배열은 경계 처리를 위해 N+1 x M+1 크기 (1-based 개념 사용)
    vector<vector<ll>> P(N + 1, vector<ll>(M + 1, 0)); 

    // 1. 행렬 A 입력 및 2D 누적 합 P 계산
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
            // P[r+1][c+1] = A[0..r][0..c]의 합
            // P[i+1][j+1] = P[i][j+1] + P[i+1][j] - P[i][j] + A[i][j]
            P[i + 1][j + 1] = P[i][j + 1] + P[i + 1][j] - P[i][j] + A[i][j];
        }
    }

    // 결과 행렬 B의 크기 계산
    int N_prime = (N - K) / S + 1;
    int M_prime = (M - K) / S + 1;

    // 커널 중심까지의 거리 (0-based)
    int center_offset = K / 2;
  

    // 2. 누적 합을 이용해 컨볼루션 결과 B 계산
    for (int i = 0; i < N_prime; ++i) { // B 행 인덱스
        for (int j = 0; j < M_prime; ++j) { // B 열 인덱스
            // 현재 커널의 좌상단 좌표 (A 행렬의 0-based index)
            int r_start = i * S;
            int c_start = j * S;

            // 커널 중심 픽셀의 A 행렬 인덱스 (0-based)
            int R_center = r_start + center_offset;
            int C_center = c_start + center_offset;

            // 1. 중심 행의 합 (r1=r2=R_center, c1=c_start, c2=c_start+K-1)
            ll row_sum = calculate_sum(P, R_center, c_start, R_center, c_start + K - 1);

            // 2. 중심 열의 합 (c1=c2=C_center, r1=r_start, r2=r_start+K-1)
            ll col_sum = calculate_sum(P, r_start, C_center, r_start + K - 1, C_center);

            // 3. 중앙 픽셀 값 (A 배열 접근은 0-based)
            ll center_val = A[R_center][C_center];

            ll B_ij = row_sum + col_sum - center_val;

            cout << B_ij << (j == M_prime - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}