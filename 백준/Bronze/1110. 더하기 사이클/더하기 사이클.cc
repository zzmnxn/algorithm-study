#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int result = 1;
    int a = n;
    int num1 = a % 10;
    int num2 = a / 10 + a % 10;
    if (num2 >= 10) {
        num2 = num2 % 10;
    }
    a = num1 * 10 + num2;
    while (a != n) {
        num1 = a % 10;
        num2 = a / 10 + a % 10;
        if (num2 >= 10) {
            num2 = num2 % 10;
        }
        a = num1 * 10 + num2;
        result++;
    }
    
    cout << result;

  
    return 0;
}

