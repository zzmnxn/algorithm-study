#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;
const ll INF = 4e18; 

// 펜윅 트리 (Binary Indexed Tree)
// 개수(cnt)와 비용 합(sum) 두 가지를 관리합니다.
struct FenwickTree {
    int size;
    vector<int> tree_cnt;
    vector<ll> tree_sum;

    FenwickTree(int n) : size(n), tree_cnt(n + 1, 0), tree_sum(n + 1, 0) {}

    // 값 업데이트 (idx: 압축된 좌표 순위)
    // delta: 1이면 추가, -1이면 제거
    // cost: 실제 비용
    void update(int idx, int delta, ll cost) {
        for (; idx <= size; idx += idx & -idx) {
            tree_cnt[idx] += delta;
            tree_sum[idx] += (cost * delta);
        }
    }

    int query_cnt(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) res += tree_cnt[idx];
        return res;
    }

    ll query_sum(int idx) {
        ll res = 0;
        for (; idx > 0; idx -= idx & -idx) res += tree_sum[idx];
        return res;
    }
};

// 전역에서 좌표 압축된 비용 참조를 위해
vector<ll> compressed_costs;
FenwickTree* bit;

// k개의 최소 비용 합을 구하는 헬퍼 함수
ll get_sum_k_smallest(int k) {
    if (k <= 0) return 0;
    int total_items = bit->query_cnt(bit->size);
    if (total_items < k) return INF;

    // Binary lifting 시작값을 안전하게 구함
    int idx = 0;
    int current_cnt = 0;
    int step = 1;
    while ((step << 1) <= bit->size) step <<= 1;

    for (; step > 0; step >>= 1) {
        if (idx + step <= bit->size && current_cnt + bit->tree_cnt[idx + step] < k) {
            idx += step;
            current_cnt += bit->tree_cnt[idx];
        }
    }
    idx++; // idx가 k번째 원소가 있는 위치(Rank)

    ll sum_up_to_idx = bit->query_sum(idx);
    int cnt_up_to_idx = bit->query_cnt(idx);

    // 같은 가격의 물건이 여러 개 있을 때, k개를 초과해서 더해졌다면 빼줌
    // compressed_costs는 0-based, BIT는 1-based index
    ll val = compressed_costs[idx - 1]; 
    int excess = cnt_up_to_idx - k;
    
    return sum_up_to_idx - (val * excess);
}

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;

    int M, cnt_A_pref, cnt_B_pref;
    cin >> M >> cnt_A_pref >> cnt_B_pref;

    vector<ll> raw_costs(K + 1);
    for (int i = 1; i <= K; ++i) cin >> raw_costs[i];

    vector<bool> is_Hanbyeol(K + 1, false);
    for (int i = 0; i < cnt_A_pref; ++i) {
        int idx; cin >> idx; is_Hanbyeol[idx] = true;
    }

    vector<bool> is_Eunha(K + 1, false);
    for (int i = 0; i < cnt_B_pref; ++i) {
        int idx; cin >> idx; is_Eunha[idx] = true;
    }

    // 그룹 분류
    vector<ll> AB, A, B, O;
    for (int i = 1; i <= K; ++i) {
        if (is_Hanbyeol[i] && is_Eunha[i]) AB.push_back(raw_costs[i]);
        else if (is_Hanbyeol[i]) A.push_back(raw_costs[i]);
        else if (is_Eunha[i]) B.push_back(raw_costs[i]);
        else O.push_back(raw_costs[i]);
    }

    // 초기 불가능 조건 체크
    if (AB.size() + A.size() < M || AB.size() + B.size() < M) {
        cout << -1 << "\n";
        return;
    }

    sort(AB.begin(), AB.end());
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(O.begin(), O.end());

    // 좌표 압축 준비
    compressed_costs = AB;
    compressed_costs.insert(compressed_costs.end(), A.begin(), A.end());
    compressed_costs.insert(compressed_costs.end(), B.begin(), B.end());
    compressed_costs.insert(compressed_costs.end(), O.begin(), O.end());
    
    sort(compressed_costs.begin(), compressed_costs.end());
    compressed_costs.erase(unique(compressed_costs.begin(), compressed_costs.end()), compressed_costs.end());

    // 비용 -> Rank 매핑 함수
    auto get_rank = [&](ll cost) {
        return (int)(lower_bound(compressed_costs.begin(), compressed_costs.end(), cost) - compressed_costs.begin() + 1);
    };

    // BIT 초기화 및 모든 아이템 삽입
    bit = new FenwickTree((int)compressed_costs.size());
    
    // 처음에 모든 아이템을 Pool(BIT)에 넣음
    for (ll c : AB) bit->update(get_rank(c), 1, c);
    for (ll c : A) bit->update(get_rank(c), 1, c);
    for (ll c : B) bit->update(get_rank(c), 1, c);
    for (ll c : O) bit->update(get_rank(c), 1, c);

    ll min_total_cost = INF;
    ll current_fixed_cost = 0;

    // x=0 일 때의 초기 Mandatory 설정 (k = M)
    int cur_req_A = M; // max(0, M - 0)
    int cur_req_B = M; // max(0, M - 0)

    for(int i=0; i<cur_req_A && i<(int)A.size(); ++i) {
        current_fixed_cost += A[i];
        bit->update(get_rank(A[i]), -1, A[i]);
    }
    for(int i=0; i<cur_req_B && i<(int)B.size(); ++i) {
        current_fixed_cost += B[i];
        bit->update(get_rank(B[i]), -1, B[i]);
    }

    // x 순회 (0 부터 AB.size() 까지)
    for (int x = 0; x <= (int)AB.size(); ++x) {
        // 1. 현재 x 상태에서의 유효성 검사 및 비용 계산
        int k = max(0, M - x);
        
        bool possible = true;
        if (k > (int)A.size()) possible = false;
        if (k > (int)B.size()) possible = false;
        
        if (possible) {
            int mandatory_cnt = x + k + k;
            if (mandatory_cnt <= N) {
                int rem_cnt = N - mandatory_cnt;
                ll rem_cost = get_sum_k_smallest(rem_cnt);
                if (rem_cost != INF) {
                    min_total_cost = min(min_total_cost, current_fixed_cost + rem_cost);
                }
            }
        }

        // 2. 다음 상태(x+1)로 전이 준비
        if (x == (int)AB.size()) break; // 더 이상 갈 곳 없음

        // 2-1. AB[x]가 Pool -> Mandatory (고정 비용 추가, BIT에서 제거)
        current_fixed_cost += AB[x];
        bit->update(get_rank(AB[x]), -1, AB[x]);

        // 2-2. A, B의 필수 개수가 줄어드는지 확인
        int next_k = max(0, M - (x + 1));
        int curr_k = max(0, M - x);

        if (next_k < curr_k) {
            // A에서 하나가 필수 해제됨 (Mandatory -> Pool)
            if (curr_k - 1 < (int)A.size()) {
                ll val = A[curr_k - 1];
                current_fixed_cost -= val;
                bit->update(get_rank(val), 1, val);
            }
            // B도 동일
            if (curr_k - 1 < (int)B.size()) {
                ll val = B[curr_k - 1];
                current_fixed_cost -= val;
                bit->update(get_rank(val), 1, val);
            }
        }
    }

    if (min_total_cost == INF) cout << -1 << "\n";
    else cout << min_total_cost << "\n";

    delete bit;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
