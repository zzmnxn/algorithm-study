//7.영어단어 복구

#include <stdio.h>
#include <stdio.h>

int main() {
    //freopen("Input.txt","rt",stdin);
    char arr[100];
    fgets(arr, sizeof(arr), stdin); // 공백 포함 입력
    int idx = 0;
    while (arr[idx] != '\0') {
        if (arr[idx] != ' ') { // 공백이 아니면
            if (arr[idx] >= 'a' && arr[idx] <= 'z') {
                arr[idx] -= 32; // 소문자를 대문자로
            }
            printf("%c", arr[idx]);
        }
        idx++;
    }
    return 0;
}
