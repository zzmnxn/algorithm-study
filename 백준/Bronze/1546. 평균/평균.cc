#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
	int n,tmp;
	cin >> n;

	double sum = 0;
	double max = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		sum += tmp;
		if (max <tmp) max = tmp;
	}
	double result = (sum * 100.0 / max) / n;
	cout << result;
	return 0;
}