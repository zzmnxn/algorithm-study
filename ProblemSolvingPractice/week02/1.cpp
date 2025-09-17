#include <iostream>
#include <vector>
#include <queue>    // priority_queue 사용
#include <functional> // std::greater 사용

// Min-Heap을 이용한 풀이
std::vector<int> findLargestN_Heap(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty()) {
        return {};
    }
    int N = matrix.size();

    // 1. 크기 N을 유지할 최소 힙(Min-Heap) 생성
    // std::greater<int>를 사용하여 작은 값이 top으로 오도록 설정
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // 2. 행렬의 모든 원소를 순회
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int current_val = matrix[i][j];

            // 힙의 크기가 N보다 작으면 무조건 삽입
            if (minHeap.size() < N) {
                minHeap.push(current_val);
            }
            // 힙이 꽉 찼고, 현재 원소가 힙의 최소값(root)보다 크면 교체
            else if (current_val > minHeap.top()) {
                minHeap.pop(); // 가장 작은 원소 제거
                minHeap.push(current_val); // 더 큰 새 원소 삽입
            }
        }
    }

    // 3. 힙에 남아있는 N개의 원소를 벡터로 옮겨 반환
    std::vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    
    // 결과는 오름차순으로 정렬되어 있음
    return result;
}
#include <iostream>
#include <vector>
#include <algorithm> // std::swap, std::vector::iterator 사용
#include <random>    // 임의의 피벗 선택을 위해 사용

// Quickselect를 이용한 풀이
namespace QuickselectSolution {
    // 배열의 특정 구간을 분할하고 피벗의 최종 위치를 반환 (Lomuto Partition Scheme)
    int partition(std::vector<int>& arr, int left, int right) {
        // 최악의 경우를 피하기 위해 임의의 피벗을 선택하고 맨 오른쪽으로 이동
        int pivot_index = left + rand() % (right - left + 1);
        int pivot_value = arr[pivot_index];
        std::swap(arr[pivot_index], arr[right]);
        
        int store_index = left;
        for (int i = left; i < right; ++i) {
            if (arr[i] < pivot_value) {
                std::swap(arr[i], arr[store_index]);
                store_index++;
            }
        }
        std::swap(arr[store_index], arr[right]);
        return store_index;
    }

    std::vector<int> findLargestN_Quickselect(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty()) {
            return {};
        }
        int N = matrix.size();
        int total_elements = N * N;

        // 1. N*N 행렬을 1차원 배열로 변환
        std::vector<int> flat_arr;
        flat_arr.reserve(total_elements);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                flat_arr.push_back(matrix[i][j]);
            }
        }

        // 2. N번째 큰 수의 인덱스를 찾음 (오름차순 기준)
        // 예: 100개 중 10번째 큰 수는 오름차순 정렬 시 90번째(인덱스 89)에 위치
        int target_index = total_elements - N;
        int left = 0;
        int right = total_elements - 1;

        // 시드 설정을 위해 난수 생성기 초기화
        srand(time(0)); 

        while (left <= right) {
            int pivot_index = partition(flat_arr, left, right);
            if (pivot_index == target_index) {
                break; // N번째 큰 수를 찾았음
            } else if (pivot_index < target_index) {
                left = pivot_index + 1; // 오른쪽 구간 탐색
            } else {
                right = pivot_index - 1; // 왼쪽 구간 탐색
            }
        }

        // 3. N번째 큰 수부터 배열의 끝까지가 상위 N개의 수
        return std::vector<int>(flat_arr.begin() + target_index, flat_arr.end());
    }
}
// --- 위 두 개의 코드를 여기에 붙여넣은 후 실행 ---

// 결과 출력 함수
void printResult(const std::string& method_name, const std::vector<int>& result) {
    std::cout << method_name << " 결과: ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {5, 2, 9},
        {12, 1, 7},
        {15, 8, 3}
    };
    int N = 3;

    std::cout << N << "x" << N << " 행렬에서 상위 " << N << "개의 숫자를 찾습니다." << std::endl;

    // Min-Heap 방식 테스트
    std::vector<int> result_heap = findLargestN_Heap(matrix);
    std::sort(result_heap.begin(), result_heap.end()); // 비교를 위해 정렬
    printResult("Min-Heap", result_heap);

    // Quickselect 방식 테스트
    std::vector<int> result_quickselect = QuickselectSolution::findLargestN_Quickselect(matrix);
    std::sort(result_quickselect.begin(), result_quickselect.end()); // 비교를 위해 정렬
    printResult("Quickselect", result_quickselect);
    
    // 예상 결과: 8 9 12 15 (Min-Heap의 경우 9 12 15)
    // 수정: N=3 이므로 상위 3개인 9, 12, 15가 나와야 합니다.
    
    return 0;
}