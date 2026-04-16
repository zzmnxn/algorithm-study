#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[10000];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	int maxidx;
	int flag = 0;
	for (int i =1; i <n; i++) {
		maxidx = n-i;
		for (int j = 0; j < n - i; j++) {
			if (arr[maxidx] < arr[j]) {
				maxidx = j;
			}
		}
		if (maxidx != n - i) {
			int tmp = arr[maxidx];
			arr[maxidx] = arr[n - i];
			arr[n - i] = tmp;
			k--;
			if (k == 0) {
				printf("%d %d", arr[maxidx], arr[n-i]);
				flag = 1;
				break;
			}
		}

	}
	if (flag== 0) {
		printf("-1");
	}
	return 0;

}
