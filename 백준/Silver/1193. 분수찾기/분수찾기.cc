#include <iostream>


using namespace std;

int main() {
	int x;
	cin >> x;
	int sum = 0;
	int i = 1;
	while (true) {
		if (sum+i >= x) {
			break;
		}
		sum += i;
		i += 1;
		
	}
	if (i % 2 != 0) {
		cout << i + 1 - x + sum << "/" << x - sum;
	}
	else {
		cout << x - sum << "/" << i + 1 - x + sum;
	}
	return 0;


}