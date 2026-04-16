#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	
	if (a*b > 0) {
		if (a > 0) {
			cout << 1;
		}
		else cout << 3;
	}

	if (a * b < 0) {
		if (a < 0) {
			cout << 2;

		}
		else cout << 4;
	}
}