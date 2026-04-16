#include <iostream>

using namespace std;


int main() {
	int N, v;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];

	}


	cin >> v;
	int sum = 0;
	for (int j = 0; j < N; j++) {
		if (v == arr[j]) {
			sum++;

		}

	}
	cout << sum << endl;
	delete[] arr;
	return 0;
}