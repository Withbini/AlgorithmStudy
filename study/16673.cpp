#include <stdio.h>
int Arr[101];

int getWine(int n, int k, int p) {
	if (n == 0) return Arr[n] = 0;
	if (n == 1) return Arr[n] = k + p;
	if (Arr[n] != 0)return Arr[n];

	return Arr[n] = getWine(n - 1, k, p) + (p*n*n + k * n);
}
int main() {
	int a, b, c, result;

	scanf("%d %d %d", &a, &b, &c);
	result = getWine(a, b, c);

	printf("%d\n", result);

	return 0;
}