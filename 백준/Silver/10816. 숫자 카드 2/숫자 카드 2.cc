#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[500001];
int n, m;
/*
int search(int x) {
	int lf = 0, ri = n - 1, mid, result=0;
	while (lf <= ri) {
		mid = (ri + lf) / 2;
		if (arr[mid] == x) {
			result++;
			if (arr[mid + 1] == x) lf = mid;
			else if (arr[mid - 1] == x) ri = mid;
		}
		else if (arr[mid] < x) lf = mid + 1;
		else ri = mid - 1;
	}
	return result;
}
배열에 찾는 수의 빈도수를 찾은 이분검색은 그 수가 나타나는 범위를 세는 것이 낫다. 
내가 쓴 거는 제대로 작동 X out of bounds 나올 수도*/

int left_bound(int x) {
	int lf = 0, ri = n - 1, mid;
	while (lf <= ri) {
		mid = (lf + ri) / 2;
		if (arr[mid] < x) {
			lf = mid + 1;
		}
		else if (arr[mid] >= x) {
			ri = mid - 1;
		}
	
	}
	return lf;
}
int right_bound(int x) {
	int lf = 0, ri = n - 1, mid;
	while (lf <= ri) {
		mid = (lf + ri) / 2;
		if (arr[mid] <=x) {
			lf = mid + 1;
		}
		else if (arr[mid] > x) {
			ri = mid - 1;
		}

	}
	return ri;
}
int main() {
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);
	int tmp;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &tmp);
		printf("%d ", right_bound(tmp)-left_bound(tmp)+1);
	}
	return 0;
}