#include <iostream>

using namespace std;

int main() {
	
	int curr= 0;
	int max = 0;
	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;
		curr = curr - a + b;
		if (curr > max) {
			max = curr;
		}


	}
	cout << max;
	return 0;
}

