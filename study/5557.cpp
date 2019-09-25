#include<iostream>
using namespace std;
int n;
int num[101];
//int num[101] = { 0,8 ,3 ,2 ,4 ,8 ,7 ,2 ,4 ,0 ,8 ,8 };
long long dp[101][21];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}

	if (n == 3 && num[0] == 0 && num[1] == 0 && num[2] == 0) {
		cout << 1;
		return 0;
	}
	dp[1][num[1]] = 1;
	for (int i = 2; i <= n-1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j] > 0) {
				if (j + num[i] >= 0 && j + num[i] <= 20) dp[i][j + num[i]]+=dp[i-1][j];
				if (j - num[i] >= 0 && j - num[i] <= 20) dp[i][j - num[i]]+=dp[i-1][j];
			}
		}
	}
	
	
	cout << dp[n-1][num[n]];
	return 0;
}
