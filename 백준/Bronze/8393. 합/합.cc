#include <iostream>


using namespace std;

int main() {
	int n;
	cin >> n;
	int hap = 0;
	for (int i = 1; i <= n; i++) {
		hap += i;
	}
	cout << hap;
	return 0;
}