#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;
	int i=1,tmp=1;
	/*while (true) {

		if (i < n) {
			i += tmp * 6;
			tmp++;

		}
		if (i > n) break;
	}
	시간초과 뜸
	*/
	while (i < n) {
		i += tmp * 6;
		tmp++;
	}
	cout << tmp;
	return 0;
}