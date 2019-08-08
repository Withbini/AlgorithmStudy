#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstdio>
#include <string>
#include <algorithm>
using namespace std;
int arr[11];
string ans="";
char cmp[9];
int visited[10];
int minval=1e9, maxval = -1000;
int k;
bool LIsBig(char a) {
	if (a == '>') return true;
	return false;
}
void dfs(int x) {
	for (int i = 1; i <= k; i++) {
		if (LIsBig(cmp[i])) {
			if (arr[i] > arr[i + 1]) ans += arr[i] + arr[i + 1];
			else return;
		}

		else if (!LIsBig(cmp[i])) {
			if (arr[i] < arr[i + 1])ans += arr[i] + arr[i + 1]; 
			else return;
		}
	}
		
		minval = min(minval,atoi(ans.c_str()));
		maxval = max(maxval, atoi(ans.c_str()));

	
	for (int i = 0; i <= 9; i++) {
		if (visited[i] == -1) {
			visited[i] = 1;
			arr[x] = i;
			dfs(x + 1);
			visited[i] = -1;
		}
	}
}

int main() {
	fill(visited, visited + sizeof(visited) / sizeof(int), -1);

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> cmp[i];
	}

	dfs(0);
	cout << maxval <<"\n" << minval;

	return 0;
}
