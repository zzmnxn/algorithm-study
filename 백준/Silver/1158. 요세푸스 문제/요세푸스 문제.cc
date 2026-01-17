#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> circle;
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		
		circle.push(i+1);
	}
	cout << "<";
	while (circle.size()>1) {
		for (int i = 0; i < k-1; i++) {
			int t = circle.front();
			circle.pop();
			circle.push(t);
		}
		cout << circle.front()<< ", ";
		circle.pop();
		
	}
	cout <<circle.front()<< ">";
	circle.pop();
	return 0;
}