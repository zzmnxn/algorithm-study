#include <iostream>
#include <string>
using namespace std;

int main() {
	while (true) {
		string s;
		getline(cin, s);
		if (s == "#") break;
		int num = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'a' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
				num++;
			}

		}
		cout << num << "\n";
	}
}