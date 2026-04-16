#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n;
	cin >> n;
	stack<long> numbers;
	for (int i = 0; i < n; i++) {
		long temp;
		cin >> temp;
		if (temp == 0) {
			numbers.pop();
		}
		else
			numbers.push(temp);

	}
	long hap = 0;
	while (!numbers.empty()) {
		hap += numbers.top();
		numbers.pop();
	}
	cout << hap;
	return 0;
}