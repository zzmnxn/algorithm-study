#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int a, n;
	a = 10;
	n = 3;
	vector<int> array(a);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		for (int j = 0; j < a; j++) {
			cin >> array[j];
		}

		sort(array.begin(), array.end(),greater<int>()); //sort함수는 index를 인자로 받아야함 front, back는 요소 반환

		cout << array[n - 1] << "\n";
	}



}