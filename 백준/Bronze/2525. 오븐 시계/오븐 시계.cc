#include <iostream>
using namespace std;

int main() {
    int a, b, time;
    cin >> a >> b >> time;


    int totalMinutes = a * 60 + b + time;

    a = (totalMinutes / 60) % 24;
    b = totalMinutes % 60;


    cout << a << " " << b << endl;

    return 0;
}
