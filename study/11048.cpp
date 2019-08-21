//#include <iostream>
//#include <algorithm>
//int D[1001][1001];
//int arr[1001][1001];
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cin >> arr[i][j];
//			D[i][j] = arr[i][j];
//		}
//	}
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			D[i][j] = max(D[i][j - 1], D[i - 1][j])+arr[i][j];
//		}
//	}
//
//	cout << D[n][m];
//	return 0;
//}