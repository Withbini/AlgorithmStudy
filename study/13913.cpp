#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;
int k, n;
queue<pair<pair<int, string>,int>>q;
int visited[100001];
void bfs(int x){
	//현재 위치 값이 k보다 크다면
	if (x > k){
		cout << x - k << "\n";
		for (int i = x; i >= k; i--){
			cout << i << " ";
		}
		return;
	}
	q.push({ { x, to_string(x) }, 0 });
	while (!q.empty()){
		int xx = q.front().first.first;
		string ss = q.front().first.second;
		int cnt = q.front().second;

		q.pop();

		//탈출조건
		if (xx == k){
			//string을 모두 변환
			cout << cnt<<"\n";
			cout << ss;
			return;
		}
		if (xx - 1 >= 0){
			if (visited[xx - 1] == 0){
				visited[xx - 1] = 1;

				q.push({ { xx - 1, ss + " " + to_string(xx - 1) }, cnt + 1 });
			}
		}

		if (xx + 1 < 100001){
			if (visited[xx + 1] == 0){
				visited[xx + 1] = 1;
				q.push({ { xx + 1, ss + " " + to_string(xx + 1) }, cnt + 1 });
			}
		}
		
		if (xx * 2 < 100001){
			if (visited[xx * 2] == 0){
				visited[xx * 2] = 1;
				q.push({ { xx * 2, ss + " " + to_string(xx * 2) }, cnt + 1 });
			}
		}
	}
}
int main(){
	cin >> n >> k;
	bfs(n);

	return 0;
}
