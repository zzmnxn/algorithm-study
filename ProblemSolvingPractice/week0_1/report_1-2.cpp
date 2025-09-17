#include <iostream>
#include <vector>
using namespace std;

int min_steps(int n) {
    int result=0;
    int i;
    for(i=2;i*i<=n;i++){
        while(n%i==0){
            n/=i;
            result+=i;
        }
        
    }
    if( n > 1 )result+=n;
    //n이 i보다 크면 오류 : 마지막에 남은 n이 가장 마지막 소인수일 경우에는 1이 아닌 것임
    //즉 n이 1보다 클 때만 result에 더하면 됨

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) {
        cout << 0 << "\n";
        return 0;
    }
    cout << min_steps(n) << "\n";
    return 0;
}