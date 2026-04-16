#include <iostream>
#include<string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string a = "666";
	int idx = 1;
	while (idx <=n) {
		int temp = stoi(a);
		temp++;
		bool find = false;
		
		for (int i = 1; i < a.length(); i++) {
			if (a[i - 1] == '6' && a[i] == '6' && a[i + 1] == '6') {
				find = true;
				break;
			}
		}
	
		if (find) {
			idx++;
		}
		//idx값 매기는 것과
		if (idx <= n) {
			a = to_string(temp);
		}
		
		
	}

	cout << a<<endl;
	

	return 0;
}