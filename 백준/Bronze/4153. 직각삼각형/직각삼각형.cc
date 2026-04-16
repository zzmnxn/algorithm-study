#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	while (true) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;
		int max = a;
		if (max < b) max = b;
		if (max < c) max = c;
		if (max * max * 2 == a * a + b * b + c * c) cout << "right"<<endl;
		else cout << "wrong" << endl;
	}

	return 0;
}