#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int amount = 0;
	int a= n / 5;
	int b = 0;
	amount = -1;
	for(int i=a;i>=0;i--){
		int remainder = n - i * 5;
		if(remainder%3==0){
			b = remainder / 3;
			amount = i + b;
			break;
		}
	}

	cout << amount;
	return 0;
}
