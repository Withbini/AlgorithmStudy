#include <stdio.h>
#include <malloc.h>
int sum0[41] = { 1 };
int sum1[41] = { 0,1 };


int fibosum0(int n) {
	if (n == 0) return 1;
	if (n == 1) return 0;
	if (n!=0&&sum0[n] != 0) return sum0[n];
	return sum0[n] = fibosum0(n - 1) + fibosum0(n - 2);
}
int fibosum1(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n!=0&&sum1[n] != 0) {
		return sum1[n];
	}
	return sum1[n] = fibosum1(n - 1) + fibosum1(n - 2);
}
int main() {
	int n;
	int *num;

	scanf("%d", &n);
	num = (int*)malloc(sizeof(int)*n);

	fibosum0(40);
	fibosum1(40);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", sum0[num[i]]);
		printf("%d\n", sum1[num[i]]);
	}

	return 0;
}
