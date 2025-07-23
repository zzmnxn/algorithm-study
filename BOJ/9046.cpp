#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;
    cin.ignore(); // 줄바꿈 문자 제거
    string *str = new string[t];

    for (int i = 0; i < t; i++)
    {
        int arr[26] = {0}; // 각 테스트케이스마다 초기화
        int max = 0;
        int maxIdx = 0;
        bool isDuplicate = false;

        getline(cin, str[i]);

        for (size_t j = 0; j < str[i].length(); j++)
        {
            // lenght 반환 은 부호 없는 정수
            // int 는 부호 있는 정수( signed)
            //  둘이 비교하면 경고 발생
            char c = str[i][j];
            if (c >= 'a' && c <= 'z')
            { // 공백 포함이므로 문자만 입력 받도록 해야함
                int idx = c - 'a';
                arr[idx]++;
                if (arr[idx] > max)
                {
                    maxIdx = idx;
                    max = arr[idx];
                    isDuplicate = false;
                }
                else if (arr[idx] == max && idx != maxIdx)
                {
                    isDuplicate = true;
                }
            }
            if (isDuplicate)
                cout << '?' << endl;
            else
                cout << (char)('a' + maxIdx) << endl;
        }

        delete[] str;
        return 0;
    }
}