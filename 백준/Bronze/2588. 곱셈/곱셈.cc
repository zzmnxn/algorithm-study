#include <iostream>
#include<string>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int r1, r2, r3, result;
	r1 = a * (b % 10);
	r2 = a * ((b /10)%10);
	r3 = a * (b / 100);
	result = a * b;
	cout << r1 << "\n" << r2 << "\n" << r3 << "\n" << result;
	return 0;
}