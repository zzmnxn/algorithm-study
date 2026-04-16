#include <iostream>
#include <string>

using namespace std;

int main() {
	string words;
	getline(cin, words);

	int num = 0;


	for (int i = 0; i < words.size(); i++) {
		if (words[i] == ' ' && i == 0) {
			continue;
		}
		if (words[i] == ' ') {
			num++;
		}
	}

	if (words[words.size() - 1] != ' ') {
		num++;
	}

	cout << num << endl;
	return 0;
}

