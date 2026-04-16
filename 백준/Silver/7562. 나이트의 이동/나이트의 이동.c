#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 300  // 최대 보드 크기 정의

// 큐에 사용할 구조체 정의
typedef struct {
    int y, x;  // y, x 좌표
} Queue;

// 큐와 방문 배열, 방향 벡터 정의
Queue q[MAX * MAX];
int visited[MAX][MAX];
int dy[8] = { -2,-1,1,2,2,1,-1,-2 }; // y 방향 이동 배열
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 }; // x 방향 이동 배열
int front, rear;  // 큐의 앞, 뒤 인덱스

// 큐 초기화 함수
void initializeQueue() {
    front = rear = 0;
}

// 큐에 요소 추가 함수
void enqueue(int y, int x) {
    q[rear].y = y;
    q[rear].x = x;
    rear++;
}

// 큐에서 요소 제거 함수
Queue dequeue() {
    return q[front++];
}

// 큐가 비었는지 확인하는 함수
int isQueueEmpty() {
    return front == rear;
}

// BFS 함수 선언
void BFS(int, int, int, int, int);

int main() {
    int t, l;  // 테스트 케이스 수와 보드 크기 변수
    int sy, sx, desy, desx;  // 시작점과 도착점 좌표 변수

    scanf("%d", &t);  // 테스트 케이스 수 입력 받기
    while (t--) {  // 각 테스트 케이스에 대해 반복
        scanf("%d", &l);  // 보드 크기 입력 받기
        scanf("%d %d", &sy, &sx);  // 시작점 좌표 입력 받기
        scanf("%d %d", &desy, &desx);  // 도착점 좌표 입력 받기

        memset(visited, 0, sizeof(visited));  // 방문 배열 초기화
        BFS(sy, sx, desy, desx, l);  // BFS 실행
        printf("%d\n", visited[desy][desx]);  // 도착점까지의 거리 출력
    }
    return 0;  // 프로그램 종료
}

// BFS 함수 정의
void BFS(int sy, int sx, int desy, int desx, int l) {
    initializeQueue();  // 큐 초기화
    enqueue(sy, sx);  // 시작점 큐에 추가
    visited[sy][sx] = 0;  // 시작점 방문 표시

    while (!isQueueEmpty()) {  // 큐가 빌 때까지 반복
        Queue cur = dequeue();  // 큐에서 요소 제거
        if (cur.y == desy && cur.x == desx) {  // 도착점에 도달하면 종료
            return;
        }
        int order = visited[cur.y][cur.x];  // 현재 위치까지의 거리
        for (int dir = 0; dir < 8; dir++) {  // 8방향으로 이동 시도
            int ny = cur.y + dy[dir];  // 새로운 y 좌표
            int nx = cur.x + dx[dir];  // 새로운 x 좌표
            if (ny >= 0 && ny < l && nx >= 0 && nx < l && !visited[ny][nx]) {  // 유효한 좌표이고 방문하지 않았으면
                enqueue(ny, nx);  // 큐에 추가
                visited[ny][nx] = order + 1;  // 방문 배열에 거리 기록
            }
        }
    }
}
