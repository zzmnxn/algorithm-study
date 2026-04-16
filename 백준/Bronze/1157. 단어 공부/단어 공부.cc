#include <iostream>
#include <string>
using namespace std;


int main() {
	string a;
	cin >> a;
	int alpha[26] = { 0 };
	for (int i = 0; i < a.length(); i++) {
		if ((int)a[i] > 96) {
			alpha[(int)a[i] - 97]++;
		}
		else alpha[(int)a[i]-65]++;
	}

	int max = 0;
	int index = 0;
	for(int j=0;j<26;j++){
		if (max < alpha[j]) {
			max = alpha[j];
			index = j;
		}

	}
	int check=0;
	for (int i = 0; i < 26; i++) {
		if (max == alpha[i]) check++;
	}
	if (check ==1) {
		cout << (char)(index+65);

	}
	else { cout << "?"; }
	return 0;

}