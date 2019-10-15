#include <iostream>
#include <algorithm>
using namespace std;
int d[16]; //n일까지 최대수익
int T[16];
int P[16];


int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> T[i];
		cin >> P[i];
		d[i] = P[i];
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (i - j >= T[j]) {
				d[i] = max(P[i] + d[j], d[i]);
			}
		}
	}
	int max = 0;

	for (int i = 1; i <= n; i++) {
		if (i + T[i] <= n + 1) {
			if (max < d[i]) {
				max = d[i];
			}
		}
	}

	cout << max;
	return 0;
}
