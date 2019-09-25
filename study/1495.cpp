#include <iostream>
#include <algorithm>
using namespace std;

int v[101];
int dp[101][1001];
int n, s, m;
//n 곡 수
//s 시작곡 볼륨
//m 최대 볼륨

int main() {
	cin >> n >> s >> m;

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

  //dp[n][m]
  //n번째 곡이 볼륨 m에서 연주할수 있는지 여부
  //1이면 연주가능, 0이면 연주
	dp[0][s] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i - 1][j] == 1) {
				if (j + v[i] <= m && j + v[i]>=0) dp[i][j + v[i]] = 1;
				if (j - v[i] <= m && j - v[i] >= 0) dp[i][j - v[i]] = 1;
			}
		}
	}

	for (int i = m; i >= 0; i--) {
		if (dp[n][i] == 1) {
			cout << i << "\n";
			break;
		}

		if (i == 0 && dp[n][i] == 0) cout << -1;
	}

	return 0;
}
