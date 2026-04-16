#include <iostream>
#include <utility>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<pair<int, int>> dotsvector;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		dotsvector.push_back(make_pair(x, y));
	}

	sort(dotsvector.begin(), dotsvector.end());

	for (int i = 0; i < n; i++) {
		cout << dotsvector[i].first << " " << dotsvector[i].second << "\n";
	}
}



