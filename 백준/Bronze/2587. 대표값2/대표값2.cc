#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> list;
	int total = 0;
	for (int i = 0; i < 5; i++) {
		int temp;
		cin >> temp;
		list.push_back(temp);
		total += temp;
	}

	sort(list.begin(), list.end());
	cout << total / 5 << "\n";
	cout << list[2];
	return 0;

}