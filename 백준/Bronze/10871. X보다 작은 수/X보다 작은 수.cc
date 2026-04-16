#include <iostream>
#include<vector>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> result;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a < x) {
			result.push_back(a);
		}

	}

	for (int c : result) {
		cout << c << " ";
	}

	return 0;
}