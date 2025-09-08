#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *cal = (int*)malloc((n+1) * sizeof(int));
    //cal은 각 숫자별 연산 횟수 저장 배열
    cal[1] = 0; // 이미 A 하나 있음

    for (int i = 2; i <= n; i++) {
        cal[i] = i; // 최악: 1씩 붙여넣기 -> i번
        for (int j = 1; j <= i/2; j++) {
            if (i % j == 0) {
                // j개에서 Copy + Paste (i/j - 1번) 해서 i개 만드는 경우
                int op = cal[j] + (i / j);
                if (op < cal[i]) cal[i] = op;
            }
        }
    }

    printf("%d\n", cal[n]);
    free(cal);
    return 0;


}
