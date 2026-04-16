#include <iostream>
#include <string>
using namespace std;

bool check(string &word) {
	for (int i = 0; i < word.length()/2; i++) {
		if (word[i] != word[word.length() - i-1]) return false;
	}
	return true;
}
int main() {
	string a;
	cin >> a;
	if (check(a)) {
		cout << 1;
	}
	else cout << 0;
	return 0;
}