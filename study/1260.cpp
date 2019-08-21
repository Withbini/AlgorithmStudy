//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//vector<int>vec[1001];
//vector<int>vec2[1001];
//bool visited1[1001] = { false };
//bool visited2[1001] = { false };
//queue<int>q;
//
////재귀 이용
//void dfs(int x) {
//	//방문했음
//	visited1[x] = true;
//	//표시
//	printf("%d ", x);
//
//	//리스트에서 방문 안한 곳 있으면 방문
//	for (unsigned int i = 0; i < vec[x].size(); i++) {
//		int y = vec[x][i];
//		if (visited1[y] == false) {
//			dfs(y);
//		}
//	}
//}
//
//void bfs(int x) {
//	visited2[x] = true;
//	q.push(x);
//
//	while (!q.empty()) {
//		int xx = q.front(); q.pop();
//		printf("%d ", xx);
//		for (unsigned int i = 0; i < vec2[xx].size(); i++) {
//			int y = vec2[xx][i];
//			if (visited2[y] == false) {
//				visited2[y] = true; q.push(y);
//			}
//		}
//	}
//}
//int main() {
//	int n, m, v;
//	cin >> n >> m >> v;
//	int a, b;
//	for (int i = 0; i < m; i++) {
//		scanf("%d %d", &a, &b);
//		vec[a].push_back(b); vec[b].push_back(a);
//		vec2[a].push_back(b); vec2[b].push_back(a);
//	}
//
//	for (int i = 1; i <= n; i++) {
//		sort(vec[i].begin(), vec[i].end());
//		sort(vec2[i].begin(), vec2[i].end());
//	}
//
//	dfs(v);
//	printf("\n");
//	bfs(v);
//
//	return 0;
//}