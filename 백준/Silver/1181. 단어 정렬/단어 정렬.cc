#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool Alphabetic(const string &a,const string &b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();

	}
	return a < b;
}
bool duplicatecheck(const string& word, const string* words, int curridx) {
	for (int i = 0; i < curridx; i++) {
		if (word == words[i]) {
			return true;
		}
	}
	return false;

}

int main() {
	int n;
	cin >> n;
	
	string* words= new string[n];
	int finalcount = 0;

	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		if (!duplicatecheck(word, words, finalcount)) {
			words[finalcount]=word;
			finalcount++;
		}

	}

	sort(words, words + finalcount,Alphabetic);

	for (int j = 0; j < finalcount; j++) {
		
		cout << words[j] << "\n";

	}

	delete[] words;

	return 0;
}
