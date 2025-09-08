#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> people(n, vector<int>(n));
    string line;

    for (int i = 0; i < n; i++) {
        cin >> line;
        for (int j = 0; j < n; j++) {
            people[i][j] = (line[j] == 'Y');
        }
    }

    int maxCount = 0;
    for (int i = 0; i < n; i++) {
        vector<bool> visited(n, false);  // 친구/2-친구 표시
        for (int j = 0; j < n; j++) {
            if (people[i][j]) {          // 직접 친구
                visited[j] = true;
                for (int k = 0; k < n; k++) {
                    if (people[j][k]) {  // 친구의 친구
                        visited[k] = true;
                    }
                }
            }
        }
        visited[i] = false;  // 자기 자신 제외

        int cnt = 0;
        for (bool v : visited) if (v) cnt++;
        maxCount = max(maxCount, cnt);
    }

    cout << maxCount;
}
