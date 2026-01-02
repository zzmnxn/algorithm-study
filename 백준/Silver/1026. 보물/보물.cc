#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> A;
	vector<int> B;


	for (int j = 0; j < n; j++) {
		int value;
		cin >> value;
		A.push_back(value);
	}
	for (int j = 0; j < n; j++) {
		int value;
		cin >> value;
		B.push_back(value);
	}
	
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(),greater<int>());
	int s=0;
	for (int i = 0; i < n; i++) {
		s += A[i] * B[i];
	}

	cout << s;
	return 0;

}