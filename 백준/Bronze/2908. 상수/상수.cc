#include <iostream>
#include<string>

using namespace std;

int reverse(string n) {
	string result;
	for (int i = 0; i < n.length(); i++) {
		result += n[n.length()-1 - i];
	}
	return stoi(result);
}

int main() {
	string a, b;
	cin >> a >> b;
	int a_r = reverse(a);
	int b_r = reverse(b);

	if (a_r > b_r) {
		cout << a_r;

	}
	else cout << b_r;
	return 0;
}

