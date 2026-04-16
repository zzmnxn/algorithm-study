#include <iostream>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	int *array;
	array = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	int result = 0;
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				result = array[i] + array[j] + array[k];
				if (result <= m&& result>max) {
					max = result;
				}
			}
		}
	}
	cout << max << endl;
	delete[] array;
	return 0;
}