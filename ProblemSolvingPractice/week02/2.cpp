#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min 사용

// 'Maximal Rectangle' 문제를 해결하는 솔루션 클래스
class Solution {
public:
    int maximalRectangle(const std::vector<std::vector<char>>& matrix) {
        // 행렬이 비어있는 경우 0을 반환
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        // 1. DP를 위한 배열 초기화
        // height: 현재 행까지 연속된 '1'의 높이
        // left: 현재 높이를 기준으로 한 직사각형의 왼쪽 경계
        // right: 현재 높이를 기준으로 한 직사각형의 오른쪽 경계 (열린 구간)
        std::vector<int> height(cols, 0);
        std::vector<int> left(cols, 0);
        std::vector<int> right(cols, cols); // 오른쪽 경계는 N으로 초기화

        int max_area = 0;

        // 2. 행 단위 순회 (i: row)
        for (int i = 0; i < rows; ++i) {
            int current_left = 0;
            int current_right = cols;

            // 2-1. 첫 번째 탐색 (왼쪽 -> 오른쪽): height와 left 배열 갱신
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    // 높이 갱신: 이전 행의 높이에 1을 더함
                    height[j]++;
                    // 왼쪽 경계 갱신: max(이전 행의 경계, 현재 행의 '1' 시작점)
                    left[j] = std::max(left[j], current_left);
                } else {
                    // '0'을 만나면 모든 정보 초기화
                    height[j] = 0;
                    left[j] = 0;
                    // 새로운 '1' 구간의 시작점은 현재 위치 다음
                    current_left = j + 1;
                }
            }

            // 2-2. 두 번째 탐색 (오른쪽 -> 왼쪽): right 배열 갱신
            for (int j = cols - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    // 오른쪽 경계 갱신: min(이전 행의 경계, 현재 행의 '1' 끝점)
                    right[j] = std::min(right[j], current_right);
                } else {
                    // '0'을 만나면 경계 초기화
                    right[j] = cols;
                    // 새로운 '1' 구간의 끝점은 현재 위치
                    current_right = j;
                }
            }

            // 2-3. 세 번째 탐색 (넓이 계산 및 최댓값 갱신)
            for (int j = 0; j < cols; ++j) {

                int current_area = height[j] * (right[j] - left[j]);
                max_area = std::max(max_area, current_area);
            }
            for (int j = 0; j < cols; ++j) {
                std::cout<<left[j]<<" ";
            }
            std::cout<<"\n";
            for (int j = 0; j < cols; ++j) {
                std::cout<<right[j]<<" ";
            }
            std::cout<<"\n";
        }

        return max_area;
    }
};

// --- 테스트를 위한 메인 함수 ---
int main() {
    Solution sol;

    // 테스트 케이스
    std::vector<std::vector<char>> matrix = {
        {'1', '0', '1', '0'},
        {'1', '1', '1', '1'},
        {'1', '1', '1', '0'},
        {'1', '0', '0', '1'}
    };

    int result = sol.maximalRectangle(matrix);
    std::cout << "가장 큰 사각형의 넓이는: " << result << std::endl; // 예상 결과: 6

    return 0;
}