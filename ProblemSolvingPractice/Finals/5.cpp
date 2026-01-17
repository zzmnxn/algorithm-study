#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map> // map은 입력 처리를 위해 사용

using namespace std;

typedef long long ll;
const ll INF = 4e18; // 충분히 큰 값

// (이전 코드의 입력 및 그룹 분류 로직은 동일하게 진행됩니다.)
// 1. 입력 및 선호도 처리
// 2. 그룹 분류 (AB, A, B, O) 및 정렬
// 3. 누적 합 배열 계산 (A, B, AB 그룹만)

void solve_naive() {
    int N, K;
    if (!(cin >> N >> K)) return;

    int M, A_count, B_count;
    cin >> M >> A_count >> B_count;

    vector<ll> costs(K + 1);
    for (int i = 1; i <= K; ++i) cin >> costs[i];

    // Map을 사용하여 O(1)에 선호도 체크
    map<int, bool> hanbyeol_prefs;
    for (int i = 0; i < A_count; ++i) { int idx; cin >> idx; hanbyeol_prefs[idx] = true; }
    map<int, bool> eunha_prefs;
    for (int i = 0; i < B_count; ++i) { int idx; cin >> idx; eunha_prefs[idx] = true; }

    // 2. 그룹 분류 및 비용 정렬
    vector<ll> AB, A, B, O;
    for (int i = 1; i <= K; ++i) {
        bool is_a = hanbyeol_prefs[i];
        bool is_b = eunha_prefs[i];
        if (is_a && is_b) AB.push_back(costs[i]);
        else if (is_a) A.push_back(costs[i]);
        else if (is_b) B.push_back(costs[i]);
        else O.push_back(costs[i]);
    }

    sort(AB.begin(), AB.end());
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(O.begin(), O.end());

    // 3. 누적 합 배열 계산 (필수 선택 비용을 O(1)에 찾기 위함)
    vector<ll> AB_sum(AB.size() + 1, 0);
    for (int i = 0; i < AB.size(); ++i) AB_sum[i + 1] = AB_sum[i] + AB[i];

    vector<ll> A_sum(A.size() + 1, 0);
    for (int i = 0; i < A.size(); ++i) A_sum[i + 1] = A_sum[i] + A[i];

    vector<ll> B_sum(B.size() + 1, 0);
    for (int i = 0; i < B.size(); ++i) B_sum[i + 1] = B_sum[i] + B[i];

    // 초기 불가능 조건 체크
    if (AB.size() + A.size() < M || AB.size() + B.size() < M) {
        cout << -1 << "\n";
        return;
    }
    
    ll min_cost = INF;

    // 4. x 순회 (AB에서 선택할 개수)
    for (int x = 0; x <= (int)AB.size(); ++x) {
        ll current_cost = 0;
        int current_N = 0;
        
        // 4-1. AB에서 x개 선택 (가장 싼 x개)
        current_cost += AB_sum[x];
        current_N += x;
        
        // 4-2. A, B 그룹에서 추가 필수 개수 k 계산
        int k = max(0, M - x);
        
        // 필수 개수를 채울 수 없는 경우
        if (k > A.size() || k > B.size()) continue;

        // A에서 k개 선택 (가장 싼 k개)
        current_cost += A_sum[k];
        current_N += k;

        // B에서 k개 선택 (가장 싼 k개)
        current_cost += B_sum[k];
        current_N += k;
        
        // 5. 남은 N_rem 개수 채우기 (나이브 부분)
        int N_rem = N - current_N;
        if (N_rem < 0) continue; 
        
        // 남은 후보(Pool)를 하나의 벡터에 모으기
        vector<ll> remaining_candidates;
        
        // A 그룹 (k개 선택 후 남은 것)
        for (int i = k; i < A.size(); ++i) {
            remaining_candidates.push_back(A[i]);
        }
        // B 그룹 (k개 선택 후 남은 것)
        for (int i = k; i < B.size(); ++i) {
            remaining_candidates.push_back(B[i]);
        }
        // O 그룹 전체
        remaining_candidates.insert(remaining_candidates.end(), O.begin(), O.end());
        
        // --- 여기서 시간 복잡도가 높아집니다 ---
        // 6. 남은 후보를 정렬하고 N_rem개를 더합니다.
        // N_rem이 0일 수 있으므로 정렬 전에 크기 체크
        if (remaining_candidates.size() < N_rem) continue; 

        // O(K log K) 또는 O(N log N) 연산이 매번 발생
        sort(remaining_candidates.begin(), remaining_candidates.end()); 

        // 가장 저렴한 N_rem개를 선택하여 비용 추가
        for (int i = 0; i < N_rem; ++i) {
            current_cost += remaining_candidates[i];
        }

        min_cost = min(min_cost, current_cost);
    }

    if (min_cost == INF) cout << -1 << "\n";
    else cout << min_cost << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve_naive();
    return 0;
}
// 밑에가 40점


/*#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>

using namespace std;

typedef long long ll;
const ll INF = 4e18; // N * max_cost (3e5 * 1e9 = 3e14) 보다 큰 충분히 큰 값

struct Appliance {
    int index;
    ll cost;
    bool is_hanbyeol;
    bool is_eunha;
};

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;

    int M, A_count, B_count;
    cin >> M >> A_count >> B_count;

    // 1. 비용 데이터 읽기 및 선호도 설정
    vector<ll> costs(K + 1); // 1-based index
    for (int i = 1; i <= K; ++i) {
        cin >> costs[i];
    }

    vector<int> a_pref(A_count);
    map<int, bool> hanbyeol_prefs;
    for (int i = 0; i < A_count; ++i) {
        cin >> a_pref[i];
        hanbyeol_prefs[a_pref[i]] = true;
    }

    vector<int> b_pref(B_count);
    map<int, bool> eunha_prefs;
    for (int i = 0; i < B_count; ++i) {
        cin >> b_pref[i];
        eunha_prefs[b_pref[i]] = true;
    }

    // 2. 그룹 분류 및 비용 정렬
    vector<ll> AB, A, B, O;
    for (int i = 1; i <= K; ++i) {
        bool is_a = hanbyeol_prefs[i];
        bool is_b = eunha_prefs[i];

        if (is_a && is_b) {
            AB.push_back(costs[i]);
        } else if (is_a) {
            A.push_back(costs[i]);
        } else if (is_b) {
            B.push_back(costs[i]);
        } else {
            O.push_back(costs[i]);
        }
    }

    // 각 그룹의 비용을 오름차순으로 정렬
    sort(AB.begin(), AB.end());
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(O.begin(), O.end());

    // 3. Prefix Sum 계산 (AB, A, B 그룹)
    vector<ll> AB_sum(AB.size() + 1, 0);
    for (int i = 0; i < AB.size(); ++i) AB_sum[i + 1] = AB_sum[i] + AB[i];

    vector<ll> A_sum(A.size() + 1, 0);
    for (int i = 0; i < A.size(); ++i) A_sum[i + 1] = A_sum[i] + A[i];

    vector<ll> B_sum(B.size() + 1, 0);
    for (int i = 0; i < B.size(); ++i) B_sum[i + 1] = B_sum[i] + B[i];

    // 4. 최소 비용 탐색
    ll min_cost = INF;

    // x: AB 그룹에서 선택할 개수
    // x의 하한: 2*M - N (만약 N < 2M 이면)
    // x의 상한: min(M, |AB|)
    int x_min = max(0, 2 * M - N);
    int x_max = min({N, (int)AB.size(), M});

    for (int x = x_min; x <= x_max; ++x) {
        // x개의 AB 제품 선택 비용
        ll current_cost = AB_sum[x];
        int current_N = x;

        // k: A, B 그룹에서 추가로 선택해야 하는 최소 개수
        int k = M - x;
        
        // k개의 A 제품 선택
        if (k > A.size()) continue; // A 그룹만으로는 M을 채울 수 없음 (이 경우는 이미 is_possible에서 걸렀거나, x가 작아서 발생)
        current_cost += A_sum[k];
        current_N += k;

        // k개의 B 제품 선택
        if (k > B.size()) continue; // B 그룹만으로는 M을 채울 수 없음
        current_cost += B_sum[k];
        current_N += k;

        // 5. 남은 개수 N_rem 채우기
        int N_rem = N - current_N;
        if (N_rem < 0) continue; // N개를 초과하는 경우 (실제로는 x_max 범위 때문에 발생하지 않음)
        
        // 남은 후보 (A_rem, B_rem, O)를 하나의 벡터로 합침
        vector<ll> remaining_candidates;
        
        // A 그룹 (k개 선택 후 남은 것)
        for (int i = k; i < A.size(); ++i) {
            remaining_candidates.push_back(A[i]);
        }
        // B 그룹 (k개 선택 후 남은 것)
        for (int i = k; i < B.size(); ++i) {
            remaining_candidates.push_back(B[i]);
        }
        // O 그룹 전체
        for (ll cost : O) {
            remaining_candidates.push_back(cost);
        }

        // 남은 후보가 N_rem보다 적으면 N개를 채울 수 없습니다.
        if (remaining_candidates.size() < N_rem) continue;

        // 남은 후보들을 비용 순으로 정렬 (이미 A, B, O는 정렬되어 있지만, 합친 후 다시 정렬해야 함)
        sort(remaining_candidates.begin(), remaining_candidates.end());

        // 가장 저렴한 N_rem개를 선택하여 비용 추가
        for (int i = 0; i < N_rem; ++i) {
            current_cost += remaining_candidates[i];
        }

        min_cost = min(min_cost, current_cost);
    }

    // 6. 결과 출력
    if (min_cost == INF) {
        cout << -1 << "\n";
    } else {
        cout << min_cost << "\n";
    }
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}*/