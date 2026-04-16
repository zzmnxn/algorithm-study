#include <iostream>

using namespace std;

int main() {
    int arr[10];
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
    }
    int max = arr[0];
    for (int j = 0; j < 9; j++) {
        if (max <= arr[j]) {
            max = arr[j];
        }
    }
    cout << max<<endl;
    for (int j = 0; j < 9; j++) {
        if (max == arr[j]) {
            cout << j + 1 << endl;
            break;
        }
    }
    
    return 0;
}