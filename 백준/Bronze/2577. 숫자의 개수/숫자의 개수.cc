#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int result = a * b * c;

	int array[2][10] = { 0, };
	for (int i = 0; i < 10; i++) {
		array[0][i] = i;
	}

	while (result >=1) {
		int temp = result % 10;
		array[1][temp]++;
		result = result / 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << array[1][i] << "\n";
	}
}



