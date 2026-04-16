#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie();  //이거하면 시간 줄어듦 이유 더 연구

	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n); //내장 함수 사용
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";  //endl은 버퍼를 비워줘서 시간이 오래걸린다고 알고 있음
	}
	


	delete[] arr;
	return 0;
}

