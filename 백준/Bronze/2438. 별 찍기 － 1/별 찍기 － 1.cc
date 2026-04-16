#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int j = 0;
    for (int i = 1; i <= n; i++) {
        for (j = 0; j < i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}