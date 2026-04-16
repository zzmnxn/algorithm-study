#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int idx = 0;
	for (int i = n; i >0; i--) {
		for (int k = 0; k < idx; k++) {
				cout << " ";
		}
		for (int j = 0; j < 2 * i - 1; j++) {
			cout << "*";
		}
		idx++;
		cout << "\n";
		
	}
}