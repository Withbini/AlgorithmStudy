#include <iostream>
#include <cstdio>

using namespace std;

int max(int a, int b) { 
	return (a > b) ? a : b; 
}

int main() {
	int t, n;
	scanf("%d", &t);

	while (t--) {
		//d는 최대점수
		//a는 스티커점수
		int d[2][100001], a[2][100001];

		cin >> n;

		for (int i = 0; i <= 1; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &a[i][j]);
			}
		}


		d[0][0] = d[1][0] = 0;
		d[0][1] = a[0][1];
		d[1][1] = a[1][1];

		for (int i = 2; i <= n; i++) {
			d[0][i] = max(d[1][i - 1], d[1][i - 2]) + a[0][i];
			d[1][i] = max(d[0][i - 1], d[0][i - 2]) + a[1][i];
		}

		cout << max(d[1][n], d[0][n]);
		cout << "\n";
	}

	return 0;
}
