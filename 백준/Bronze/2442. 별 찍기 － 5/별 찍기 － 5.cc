#include <iostream>


using namespace std;

int main() {
	int x;
	cin >> x;
	for (int i = 0; i < x; i++) {
		for (int j = x-i; j > 1; j--) {
			cout << " ";
		}
		for (int j = 0; j < 2 * i + 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	
	return 0;


}