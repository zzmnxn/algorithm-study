#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // seen_b[i] : i번째 건물을 볼 수 있는 다른 건물들의 인덱스 목록
    vector<vector<int>> seen_b(n);

    for (int j = 0; j < n; j++) {
        // 1. 현재 건물(j)에서 오른쪽(i > j)에 있는 높은 건물들이 나를 볼 수 있는지 확인
        if (j < n - 1) {
            // 바로 옆 건물(j+1)은 무조건 서로 보임
            double max_slope = (double)(arr[j+1] - arr[j]);
            seen_b[j+1].push_back(j); // j+1번 건물이 j를 볼 수 있음

            for (int i = j + 2; i < n; i++) {
                double cur_slope = (double)(arr[i] - arr[j]) / (i - j);
                if (cur_slope > max_slope) {
                    seen_b[i].push_back(j); // i번 건물이 j를 볼 수 있음
                    max_slope = cur_slope;
                }
            }
        }

        // 2. 현재 건물(j)에서 왼쪽(i < j)에 있는 높은 건물들이 나를 볼 수 있는지 확인
        if (j > 0) {
            // 바로 왼쪽 건물(j-1)은 무조건 서로 보임
            double min_slope = (double)(arr[j-1] - arr[j]) / (-1);
            seen_b[j-1].push_back(j); // j-1번 건물이 j를 볼 수 있음

            for (int i = j - 2; i >= 0; i--) {
                double cur_slope = (double)(arr[i] - arr[j]) / (i - j);
                // 왼쪽 방향은 기울기가 더 작아져야(절대값은 커져야) 보임
                if (cur_slope < min_slope) {
                    seen_b[i].push_back(j); // i번 건물이 j를 볼 수 있음
                    min_slope = cur_slope;
                }
            }
        }
    }

    // 결과 출력: 각 i 건물이 볼 수 있었던 j 건물의 개수 중 최댓값
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        if (max_val < seen_b[i].size()) {
            max_val = seen_b[i].size();
        }
    }

    cout << max_val;
    return 0;
}