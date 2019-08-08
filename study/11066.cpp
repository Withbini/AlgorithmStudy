#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int d[501][501];//d[i][j] i부터 j까지의 파일의 최소 합
int t, k;
int arr[501],sum[501];

int func(int x, int y) {
	if (d[x][y] != 0x3f3f3f3f)return d[x][y];
	if (x == y) return 0;
	if (y==x+1) return d[x][y]=arr[x]+arr[y];

	for (int mid = x; mid < y; mid++) {
		d[x][y] = min(d[x][y],func(x, mid) + func(mid + 1, y));
	}

	return d[x][y] += sum[y] - sum[x - 1];
}
int main() {
	
	cin >> t;
	while (t--) {
		memset(d, 0x3f3f3f3f, sizeof(d));
		memset(sum, 0, sizeof(sum));
		cin >> k;
		for (int i = 1; i <= k; i++) {
			cin >> arr[i];
			sum[i] =sum[i-1]+ arr[i];
		}


		cout << func(1,k)<<"\n";
	}
	return 0;
}
