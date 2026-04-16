#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <cstdio>  // scanf, printf 사용
#include <string>
using namespace std;

int main() {
    int n, m;
    // scanf를 사용하여 정수 입력
    scanf("%d %d", &n, &m);

    // Unordered map to store website-password pairs
    unordered_map<string, string> arr;

    // Input website and password pairs
    for (int i = 0; i < n; i++) {
        char hp[21], pw[21];  // 최대 20자 문자열 가정 (입력 문자열 크기)
        // scanf를 사용하여 문자열 입력
        scanf("%s %s", hp, pw);
        arr[hp] = pw;  // 문자열을 unordered_map에 저장
    }

    // Find and print passwords for the given websites
    for (int i = 0; i < m; i++) {
        char find[21];  // 최대 20자 문자열 가정
        // scanf를 사용하여 검색할 문자열 입력
        scanf("%s", find);
        // 검색된 비밀번호 출력
        printf("%s\n", arr[find].c_str());  // C 스타일 출력
    }

    return 0;
}
