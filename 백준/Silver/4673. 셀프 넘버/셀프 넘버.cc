#include <iostream>

using namespace std;

int selfnumber(int n) {
	int result = n;
	while (n >=1) {
		int temp = n % 10;
		result += temp;
		n /= 10;
	}
	return result;
}

int main() {
	bool selfnum[10001] = { 0 };

	
	for (int i = 1; i <= 10000; i++) {
		int num = selfnumber(i);
		while (num <= 10000) {
			selfnum[num] = 1;
			num = selfnumber(num);
		}
	}

	for (int i = 1; i <= 10000; i++) {
		if (!selfnum[i]) {
			cout << i  << "\n";
		}
	}

	return 0;
}