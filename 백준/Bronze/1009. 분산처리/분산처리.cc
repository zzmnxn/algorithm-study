#include <iostream>

using namespace std;

/*long long power(int base, int exponent) {
    long long result = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % 10;
        }
        base = (base * base) % 10;
        exponent /= 2;
    }
    //이진거듭제곱 알고리즘
    return result;
}*/
//pow함수는 항상 부동소수점 형식이기 때문에 정수로 변환할 때 주의가 필요함
//반복문으로 해도 큰 숫자일수록 int의 표현 범위를 벗어나면 오버플로우의 문제가 발생할 수 있기 때문에 
//중간중간에 오버플로우를 방지해줘야함
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int a, b;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        int tmp = 1;
        for (int j = 0; j < b; j++) {
            tmp = (tmp * a) % 10;

        }
        if (tmp == 0) {
            cout << 10 << "\n";
        }
        else {
            cout << tmp << "\n";
        }
    }

    return 0;
}
