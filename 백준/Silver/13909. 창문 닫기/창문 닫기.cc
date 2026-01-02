#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int num = 0;
    for (int i = 1; i * i <= n; i++) {
        num++;
    }
    cout << num;

    return 0;
}
