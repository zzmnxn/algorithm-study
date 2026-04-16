#include <iostream>
using namespace std;

int main() {
	int a;
	cin >> a;
	for (int i = 0; i < a; i++) {
		for (int j = a - 1-i; j > 0; j--) {
			cout << " ";
		}
		for (int k = 0; k <i+1; k++) {
			cout << "*";
		}
		cout << "\n";
	}
}