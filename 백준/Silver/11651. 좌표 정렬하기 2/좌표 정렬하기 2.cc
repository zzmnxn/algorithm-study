#include <iostream>
#include <utility>
#include<vector>
#include<algorithm>
using namespace std;

bool compare_Y(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second > b.second) {
		return false;
	}
	else if (a.second == b.second) {
		return a.first < b.first;
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	
	vector<pair<int, int>> dotsvector;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		dotsvector.push_back(make_pair(x, y));
	}

	sort(dotsvector.begin(), dotsvector.end(),compare_Y);

	for (int i = 0; i < n; i++) {
		cout << dotsvector[i].first << " " << dotsvector[i].second << "\n";
	}
}



