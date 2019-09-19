#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>arr;
int n, m;
vector <int>ans;

void permutation(int x) {
	if (x == m) {
			for (int i = 0; i < m; i++) {
				printf("%d ", ans[i]);
			}
			printf("\n");
			return;
	}

	for (int i = 0; i < n; i++) {
		ans.push_back(arr[i]);
		permutation(x + 1);
		ans.pop_back();
	}
}
int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int s;
		scanf("%d", &s);
		arr.push_back(s);
	}

	sort(arr.begin(),arr.end());
	permutation(0);
	
	return 0;
}
