#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int A[100010];

void binarySearch(int tmp) {
	int ri = n - 1, li = 0, mid;
	while (ri >= li) {
		mid = (ri + li) / 2;
		if (A[mid] == tmp) {
			cout << 1 << "\n";
			return;
		}
		else if (A[mid] < tmp) {
			li = mid + 1;
		}
		else ri = mid - 1;
	}
	 cout << 0 << "\n";
	 return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//시간초과 조심
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	sort(A, A+n);
	cin >> m;

	int tmp;
	for (int j = 0; j < m; j++) {
		cin >> tmp;
		binarySearch(tmp);
	}
	return 0;

}

/*/sort(A.begin(), A.end());
cin >> m;
vector<int> B(m);
for (int j = 0; j < m; j++) {
	cin >> B[j];
}
for (int j = 0; j < m; j++) {
	bool found = false;
	int ri = n - 1, li = 0, mid;
	while (ri >= li) {
		mid = (ri + li) / 2;
		if (A[mid] == B[j]) {
			cout << 1 << "\n";
			found = true;
			break;
		}
		else if (A[mid] < B[j]) {
			li = mid + 1;
		}
		else ri = mid - 1;
	}
	if (found) cout << 0 << "\n";
}
sort 하면 원래 위치가 바뀐 다는 것을 까먹었어. */