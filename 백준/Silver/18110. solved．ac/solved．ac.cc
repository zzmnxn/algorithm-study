#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[300001];

int main() {
	int n;
	scanf("%d", &n);
	if (n == 0) {
		printf("0");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	/*if ((int)(n * 0.15) == (int)(n * 0.15 + 0.5)) {
		removenum =(int)( n * 0.15) + 1;

	}
	else removenum = (int)(n * 0.15); 
	반올림 너무 복잡하게 함*/
	int removenum = round(n * 0.15);
	//printf("%d ", removenum);
	double sum = 0;
	sort(arr, arr + n);
	for (int i = removenum; i < n - removenum; i++) {
		sum += arr[i];
	}
	int res = round(sum / (n - removenum * 2));
	printf("%d", res);
	return 0;
}