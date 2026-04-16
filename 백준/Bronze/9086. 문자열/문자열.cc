#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i=0; i < n; i++) {
		string words;
		cin >> words;
		cout << words[0] << words[words.size()-1] << "\n";
	}

	return 0;
}