// #include <iostream>
// #include <vector>

// using namespace std;

// void solve_row_wise() {
//     // 입출력 속도 향상
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int N, Q;
//     cin >> N >> Q;

//     // 1. 초기 행렬 A 입력
//     // (인덱스 편의를 위해 1-based로 N+1 크기 할당)
//     vector<vector<int>> A(N + 1, vector<int>(N + 1));
//     for (int i = 1; i <= N; ++i) {
//         for (int j = 1; j <= N; ++j) {
//             cin >> A[i][j];
//         }
//     }

//     // 보조 행렬 D 생성 (변화량 기록용)
//     // C2+1 접근을 위해 열 크기를 N+2로 할당
//     vector<vector<int>> D(N + 1, vector<int>(N + 2, 0));

//     // 2. 쿼리 처리
//     for (int k = 0; k < Q; ++k) {
//         int r1, r2, c1, c2, v;
//         cin >> r1 >> r2 >> c1 >> c2 >> v;

//         // 쿼리가 영향을 미치는 모든 행(r1 ~ r2)을 순회
//         for (int i = r1; i <= r2; ++i) {
//             // 각 행에 1차원 구간 갱신 규칙 적용
//             D[i][c1] += v;
//             D[i][c2 + 1] -= v;
//         }
//     }

//     // 3. 누적 합 계산 및 최종 결과 출력
//     for (int i = 1; i <= N; ++i) {
//         for (int j = 1; j <= N; ++j) {
//             // 3-1. 각 행의 누적 합 계산
//             D[i][j] += D[i][j - 1];
            
//             // 3-2. 초기 행렬에 변화량 적용
//             A[i][j] += D[i][j];
            
//             cout << A[i][j] << " ";
//         }
//         cout << "\n";
//     }
// }
// // 이벤트를 저장하기 위한 구조체
// struct Event {
//     int val;
//     int c1;
//     int c2;
// };

// void solve_scanline() {
//     // 입출력 속도 향상
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int N, Q;
//     cin >> N >> Q;

//     // 1. 초기 행렬 A 입력
//     vector<vector<int>> A(N + 1, vector<int>(N + 1));
//     for (int i = 1; i <= N; ++i) {
//         for (int j = 1; j <= N; ++j) {
//             cin >> A[i][j];
//         }
//     }

//     // 1. 이벤트 생성
//     // 각 행에 발생할 이벤트를 저장할 리스트
//     // (r2+1 접근을 위해 행 크기를 N+2로 할당)
//     vector<vector<Event>> events(N + 2);
//     for (int k = 0; k < Q; ++k) {
//         int r1, r2, c1, c2, v;
//         cin >> r1 >> r2 >> c1 >> c2 >> v;
//         events[r1].push_back({v, c1, c2});      // r1 행에 시작 이벤트 추가
//         events[r2 + 1].push_back({-v, c1, c2}); // r2+1 행에 종료 이벤트 추가
//     }

//     // 2. 스캔 및 계산
//     // 현재 행의 누적 변화량을 기록할 1차원 상태 배열
//     vector<int> D_row(N + 2, 0);
//     for (int i = 1; i <= N; ++i) { // 1행부터 N행까지 스캔
//         // 2-1. 현재 행(i)에서 발생하는 모든 이벤트 처리
//         if (!events[i].empty()) {
//             for (const auto& event : events[i]) {
//                 D_row[event.c1] += event.val;
//                 D_row[event.c2 + 1] -= event.val;
//             }
//         }

//         // 2-2. 현재 행의 최종 값 계산 및 출력
//         int current_change = 0;
//         for (int j = 1; j <= N; ++j) {
//             current_change += D_row[j];
//             A[i][j] += current_change;
//             cout << A[i][j] << " ";
//         }
//         cout << "\n";
//     }
// }


// int main() {
//     solve_row_wise();
//     solve_scanline();
//     return 0;
// }
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct query {
    int R1, R2, C1, C2;
    double V;
};

struct event{
    double v;
    int c1;
    int c2;
};

void matrix_addition(int N, vector<vector<double>>& A, int Q, vector<query>& queries) {
    //TODO:
    vector<vector<event>> events(N+2);

    for(int i=0;i<Q;i++){
        int r1=queries[i].R1;
        int r2=queries[i].R2;
        int c1=queries[i].C1;
        int c2=queries[i].C2;
        double v = queries[i].V;
        events[r1].push_back({v,c1,c2});
        events[r2+1].push_back({-v,c1,c2});
    }
    vector<double> Hap (N+2,0);

    for(int i=1;i<N+1;i++){
        double currentHap=0;
        while(!events[i].empty()){
            event tmp= events[i].back();
            events[i].pop_back();
            Hap[tmp.c1]+=tmp.v;
            Hap[tmp.c2+1]-=tmp.v;
        }

        for(int j=1;j<N+1;j++){
            currentHap+=Hap[j];
            A[i-1][j-1]+=currentHap;
        }


    }

}

int main() {
    // Do NOT delete these lines unless you know what you are doing:
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<double>> A(N, vector<double>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    int Q;
    cin >> Q;

    vector<query> queries(Q);
    for (int i = 0; i < Q; i++) {
        cin >> queries[i].R1 >> queries[i].C1 >> queries[i].R2 >> queries[i].C2 >> queries[i].V;
    }

    matrix_addition(N, A, Q, queries);

    cout << fixed << setprecision(12);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}