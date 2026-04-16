#include <iostream>
#include<string>
using namespace std;

bool check(string str) {
	char temp[300] = { 0, };
	for (int i = 0; i < str.length(); i++) {
		if (temp[int(str[i])] == 0) {
			temp[(int)str[i]] = i+1;
		}
		else {
			if (i+1 - temp[(int)str[i]] == 1)
				temp[int(str[i])]++;
			else {
				return false;
			}
		}
	}
	return true;
}
int main() {
	int n;
	int result = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		if (check(input))
			result++;
	}
	cout << result;
	return 0;
}
