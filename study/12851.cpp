#include <iostream>
#include <queue>
#include <utility>

using namespace std;
queue<pair<int, int>>q;
int anscnt = 0;//정답갯수
int anstime = 0;//정답 시간
int visited[300001];
int n, k;

void bfs(int x){
	q.push(make_pair(x, 0));
	visited[x] = 1;

	while (!q.empty()){
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		visited[a] = 1;

		
		//두번째방문부터는 
		if (anstime !=0 && a == k && anstime==b ) anscnt++;

		//첫방문
		if (anstime ==0 && a == k){
			anstime = b;
			anscnt++;
		}

		if (visited[a - 1] == 0 && (a - 1) >= 0){
			q.push(make_pair(a - 1, b + 1));
		}
		if (visited[a + 1] == 0 && (a + 1) <= 100000){
			q.push(make_pair(a + 1, b + 1));
		}

		if (visited[a * 2] == 0 && (a * 2) <= 100000){
			q.push(make_pair(2 * a, b + 1));
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;

	bfs(n);
	cout << anstime << "\n" << anscnt;
	return 0;
}
