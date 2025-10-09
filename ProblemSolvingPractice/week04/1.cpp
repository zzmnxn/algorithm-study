#include <bits/stdc++.h> // C++ 표준 라이브러리의 모든 헤더를 포함 (코딩 테스트에서 편리하게 사용)
using namespace std; // std 네임스페이스를 사용해 std::cout 대신 cout 등으로 짧게 쓸 수 있게 함

// 자주 사용하는 타입을 짧게 재정의
using ll = long long; // long long 타입을 ll로 정의
using Point = pair<ll, ll>; // (y, x) 좌표를 나타낼 pair<ll, ll> 타입을 Point로 정의

// 전역 변수 및 상수
const ll W = 10000000; // 2차원 평면의 크기 (너비)
int N; // 찾아야 할 마스터볼의 총 개수

// 심판(Judge) 시스템과 상호작용하는 쿼리 함수
ll ask(ll y, ll x) {
    // 만약 좌표가 유효 범위를 벗어나면, 탐색에 영향을 주지 않도록 매우 큰 값을 반환
    if (y < 0 || y >= W || x < 0 || x >= W) {
        return 4 * W * W; 
    }
    // 표준 출력으로 쿼리를 날림
    cout << '?' << ' ' << y << ' ' << x << endl;
    ll ret; // 심판 시스템으로부터 거리 제곱 값을 받음
    cin >> ret;
    return ret;
}

// 두 점 사이의 거리 제곱을 계산하는 함수 (sqrt를 사용하지 않아 오차 및 속도 문제 방지)
ll dist_sq(Point p1, Point p2) {
    ll dy = p1.first - p2.first;
    ll dx = p1.second - p2.second;
    return dy * dy + dx * dx;
}

// 쿼리 위치와 결과(거리 제곱)를 함께 저장하기 위한 구조체
struct queryInfo {
    Point p; // 쿼리를 날린 좌표 (y, x)
    ll d2;   // 해당 좌표에서 가장 가까운 마스터볼까지의 거리 제곱
};

// 함수 전방 선언 (main 함수보다 뒤에 정의된 함수를 main에서 사용하기 위함)
void solve_for_one();
void solve_for_many();
vector<Point> intersection(Point p1, ll r1_sq, Point p2, ll r2_sq);


// --------------------------------------------------
// ## Main 함수: N값에 따라 최적의 전략을 선택하여 실행
// --------------------------------------------------
int main(void) {
    // 입출력 속도 향상을 위한 설정
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N; // 마스터볼의 개수 입력
    
    // N값에 따라 다른 해결 함수를 호출하는 분기 구조
    if (N == 1) {
        // N=1인 경우는 70%를 차지하며, 삼분 탐색으로 매우 빠르고 안정적으로 풀 수 있음
        solve_for_one();
    } else {
        // N>1인 경우는 여러 개의 공이 서로에게 영향을 주므로, 비둘기집 원리를 사용해야 함
        solve_for_many();
    }

    return 0;
}


// --------------------------------------------------
// ## N=1 일 때를 위한 삼분 탐색(Ternary Search) 솔루션
// --------------------------------------------------
void solve_for_one() {
    // 삼분 탐색은 아래로 볼록한(unimodal) 함수에서 최솟값을 찾는 효율적인 알고리즘
    // N=1일 때, 특정 직선 위의 점과 마스터볼 사이의 거리는 unimodal 함수 형태를 띰

    // 1. 임의의 수직선(x=0)을 기준으로 마스터볼의 y좌표 찾기
    ll low = 0, high = W - 1;
    ll y_ball = 0;
    // 탐색 범위를 3 미만으로 좁힐 때까지 반복
    while (high - low >= 3) {
        ll m1 = low + (high - low) / 3;  // 1/3 지점
        ll m2 = high - (high - low) / 3; // 2/3 지점
        // m1에서의 거리가 더 작으면 최솟값은 m2의 왼쪽에 존재
        if (ask(m1, 0) < ask(m2, 0)) {
            high = m2;
        } else { // 그렇지 않으면 최솟값은 m1의 오른쪽에 존재
            low = m1;
        }
    }
    // 최종적으로 좁혀진 범위(2~3개) 내에서 선형 탐색으로 정확한 y좌표 찾기
    ll min_dist_sq = -1;
    for (ll y = low; y <= high; ++y) {
        ll d2 = ask(y, 0);
        if (min_dist_sq == -1 || d2 < min_dist_sq) {
            min_dist_sq = d2;
            y_ball = y;
        }
    }

    // 2. 위에서 찾은 y_ball을 기준으로 수평선을 그어 마스터볼의 x좌표 찾기
    low = 0, high = W - 1;
    ll x_ball = 0;
    while (high - low >= 3) {
        ll m1 = low + (high - low) / 3;
        ll m2 = high - (high - low) / 3;
        if (ask(y_ball, m1) < ask(y_ball, m2)) {
            high = m2;
        } else {
            low = m1;
        }
    }
    // 좁혀진 범위 내에서 선형 탐색으로 정확한 x좌표 찾기
    min_dist_sq = -1;
    for (ll x = low; x <= high; ++x) {
        ll d2 = ask(y_ball, x);
        if (min_dist_sq == -1 || d2 < min_dist_sq) {
            min_dist_sq = d2;
            x_ball = x;
        }
    }
    
    // 3. 찾은 (y_ball, x_ball)이 정답임을 마지막으로 확인
    ask(y_ball, x_ball);
}


// --------------------------------------------------
// ## N > 1 일 때를 위한 비둘기집 원리 솔루션
// --------------------------------------------------
void solve_for_many() {
    int count = 0; // 찾은 마스터볼의 개수
    set<Point> found_balls; // 이미 찾은 공의 좌표를 저장하여 중복 방지
    mt19937 rng(time(0)); // 난수 생성기 초기화
    uniform_int_distribution<ll> dist_gen(0, W - 1); // 0 ~ W-1 범위의 균등 분포 난수 생성

    // 모든 공을 찾을 때까지 반복
    while (count < N) {
        int balls_to_find = N - count; // 찾아야 할 남은 공의 개수
        vector<queryInfo> queries; // 초기 쿼리 정보를 저장할 벡터
        set<Point> used_query_points; // 중복된 위치에 쿼리하지 않기 위함

        // 비둘기집 원리: k개의 공을 찾기 위해 k+1개의 쿼리를 날림
        for (int i = 0; i < balls_to_find + 1; i++) {
            Point q_point;
            // 이전에 쿼리하지 않은 새로운 랜덤 좌표 생성
            do { q_point = {dist_gen(rng), dist_gen(rng)}; } while (used_query_points.count(q_point));
            used_query_points.insert(q_point);

            ll d2 = ask(q_point.first, q_point.second);
            // 운 좋게 바로 찾은 경우
            if (d2 == 0) {
                if (found_balls.find(q_point) == found_balls.end()) {
                    count++;
                    found_balls.insert(q_point);
                }
                goto next_turn; // 현재 턴을 종료하고 다음 공 찾기 시작
            }
            queries.push_back({q_point, d2});
        }
        
        // "투표" 방식: 모든 후보를 모아 가장 많이 겹치는 후보를 찾음
        map<Point, int> candidate_votes; // 후보 좌표별 득표수 저장
        // 모든 쿼리 쌍 (i, j)에 대해 반복
        for (size_t i = 0; i < queries.size(); i++) {
            for (size_t j = i + 1; j < queries.size(); j++) {
                // 두 쿼리 정보로 교점(후보) 계산
                vector<Point> candidates = intersection(queries[i].p, queries[i].d2, queries[j].p, queries[j].d2);
                // 각 후보의 득표수 증가
                for (Point cand : candidates) {
                    if (cand.first < 0 || cand.first >= W || cand.second < 0 || cand.second >= W) continue;
                    if (found_balls.count(cand)) continue;
                    candidate_votes[cand]++;
                }
            }
        }
        
        // 가장 많은 득표를 한 후보 찾기
        Point best_candidate = {-1, -1};
        int max_votes = 0;
        for (auto const& [cand, votes] : candidate_votes) {
            if (votes > max_votes) {
                best_candidate = cand;
                max_votes = votes;
            }
        }
        
        // 최다 득표 후보가 유효하다면, 해당 위치에 마지막 확인 쿼리
        if (best_candidate.first != -1) {
             if (ask(best_candidate.first, best_candidate.second) == 0) {
                 if (found_balls.find(best_candidate) == found_balls.end()) {
                     count++;
                     found_balls.insert(best_candidate);
                 }
             }
        }
    next_turn:; // 다음 공을 찾기 위해 루프의 처음으로 이동
    }
}

// --------------------------------------------------
// ## 두 원의 교점 계산 함수 (⭐ __int128 타입으로 오버플로우 완벽 방지)
// --------------------------------------------------
vector<Point> intersection(Point p1, ll r1_sq, Point p2, ll r2_sq) {
    vector<Point> candidates;
    // 중간 계산 값이 ll의 범위를 초과할 수 있으므로 128비트 정수 타입 __int128 사용
    __int128 x1 = p1.second, y1 = p1.first;
    __int128 x2 = p2.second, y2 = p2.first;
    
    // 두 원의 방정식을 빼서 얻는 직선(radical axis)의 방정식: ax + by = c
    __int128 a = 2 * (x2 - x1);
    __int128 b = 2 * (y2 - y1);
    __int128 c = (__int128)r1_sq - r2_sq - x1 * x1 + x2 * x2 - y1 * y1 + y2 * y2;
    
    if (a == 0 && b == 0) return candidates; // 동심원, 교점 없음

    // Case 1: b != 0 (직선이 수직선이 아닌 일반적인 경우)
    if (b != 0) {
        // y = (c - ax) / b 를 원의 방정식에 대입하여 x에 대한 2차 방정식을 만듦: ta*x^2 + tb*x + tc = 0
        __int128 k = c - b * y1;
        __int128 ta = a * a + b * b;
        __int128 tb = -2 * x1 * b * b - 2 * a * k;
        __int128 tc = b * b * x1 * x1 + k * k - b * b * r1_sq;
        
        // 판별식 delta = tb^2 - 4*ta*tc
        __int128 delta = tb * tb - 4 * ta * tc;
        if (delta >= 0) {
            // 정수 해를 찾기 위해 부동소수점 sqrt 결과값 주변을 탐색 (오차 방지)
            __int128 s_delta = sqrt((long double)delta);
            for (__int128 s_check = s_delta - 2; s_check <= s_delta + 2; s_check++) {
                if (s_check < 0) continue;
                if (s_check * s_check == delta) { // delta가 완전 제곱수인지 확인
                    s_delta = s_check;
                    // 근의 공식을 이용해 두 개의 x 해를 찾음
                    __int128 num1 = -tb + s_delta;
                    if (num1 % (2 * ta) == 0) {
                        ll cand_x = num1 / (2 * ta);
                        __int128 num_y = c - a * cand_x;
                        if (num_y % b == 0) candidates.push_back({(ll)(num_y / b), cand_x});
                    }
                    if (s_delta != 0) { // 중근이 아닌 경우
                        __int128 num2 = -tb - s_delta;
                        if (num2 % (2 * ta) == 0) {
                            ll cand_x = num2 / (2 * ta);
                            __int128 num_y = c - a * cand_x;
                            if (num_y % b == 0) candidates.push_back({(ll)(num_y / b), cand_x});
                        }
                    }
                    break;
                }
            }
        }
    } else { // Case 2: b == 0 (직선이 수직선인 경우)
        if (c % a != 0) return candidates; // 정수 해가 없음
        ll cand_x = c / a;
        // x값을 원의 방정식에 대입하여 y에 대한 2차 방정식을 품
        __int128 rhs = (__int128)r1_sq - (cand_x - x1) * (cand_x - x1);
        if (rhs >= 0) {
            ll s_rhs = sqrt((long double)rhs);
            for (ll s_check = s_rhs - 2; s_check <= s_rhs + 2; s_check++) {
                if (s_check < 0) continue;
                if ((__int128)s_check * s_check == rhs) { // rhs가 완전 제곱수인지 확인
                    s_rhs = s_check;
                    candidates.push_back({(ll)(y1 + s_rhs), cand_x});
                    if (s_rhs != 0) candidates.push_back({(ll)(y1 - s_rhs), cand_x});
                    break;
                }
            }
        }
    }
    return candidates;
}

//ㅋㅋ 내 주관 빼고 제미나이대로 하니까 되노
1
3
clean
link 0 2
move
main: env.cpp:40: bool check_connectivity(int,int): Assertion 'u!-v'failed)