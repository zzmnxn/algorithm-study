#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		vector<int> shops(t);
		for (int j = 0; j < t; j++) {
			cin>>shops[j];
		}
		
		sort(shops.begin(),shops.end());

		int distance=shops.back() - shops.front();
		cout << 2 * distance << "\n";
	}
	return 0;
}