#include <iostream>
#include <math.h>
using namespace std;

int N;
int ans = 0;
int col[16] = { 0 };

bool isPossible(int n) {
	for (int i = 1; i < n; i++) {
		if (col[n] == col[i] || n - i == abs(col[n] - col[i]))
			return false;
	}
	return true;
}
void dfs(int n) {
	if (n == N + 1) {
		ans++;
		return;
	}

	for (int i = 1; i <= N; i++) {
		col[n] = i;
		if (isPossible(n)) {
			dfs(n + 1);
		}
	}
}
int main() {

	cin >> N;
	dfs(1);
	cout << ans << endl;
	return 0;
}
