#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	char *array=new char[n];
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	int hap = 0;
	for (int j = 0; j < n; j++) {
		hap += array[j]-48;
	}
	cout << hap << endl;
	return 0;
}