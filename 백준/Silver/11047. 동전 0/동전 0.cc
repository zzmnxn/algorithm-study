#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> cointype;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		cointype.push_back(a);

	}
	int output = 0;
	while (k > 0) {
		for (int i = n - 1; i >= 0; i--) {
			int temp;
			temp = k / cointype[i];
			k %= cointype[i];
			output += temp;
		}
	}
	cout << output;
	return 0;
}