#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>

using namespace std;
int p[1001];
int ans[1001];
int min(int a, int b) {
	return (a < b) ? a : b;
}

int getCard(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			ans[i] = min(ans[i - j] + p[j], ans[i]);
		}
	}
	return 0;
}
int main() {
	int n;
	cin >> n;
	fill(ans, ans + sizeof(ans) / sizeof(int), 10001);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	ans[0] = 0;
	ans[1] = 1 * p[1];
	getCard(n);

	printf("%d", ans[n]);
	return 0;
}