#include <iostream>
#include<cstdio>

using namespace std;
int arr[10];
int visited[10];
int n, m;
void dfs(int x) {
	if (x == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[x] == -1 && arr[x-1]<=i) {
			visited[x] = 1;
			arr[x] = i;
			dfs(x + 1);
			visited[x] = -1;
		}
	}
}

int main() {
	fill(visited, visited + sizeof(visited) / sizeof(int), -1);
	scanf("%d %d", &n, &m);
	dfs(0);
	return 0;
}
