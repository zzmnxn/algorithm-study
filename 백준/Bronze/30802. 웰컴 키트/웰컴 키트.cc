#include <iostream>

using namespace std;

int main() {
	int n;
	int arr[6];
	int t, p;
	cin >> n;
	cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5];
	cin >> t >> p;
	int tshirt = 0;
	for (int i = 0; i < 6; i++) {
		int tmp = arr[i] / t;
		int r = arr[i] % t;
		if (r != 0) {
			tshirt++;
		}
		tshirt += tmp;
	}
	cout << tshirt << "\n";
	cout << n / p << " " << n % p;
	return 0;
}