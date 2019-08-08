#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

char arr[21][21];
bool visited[21][21];
int dist[21][21];
int dirtdist[12][12];//더러운 방끼리 거리
int dirt = 0;//더러운방갯수
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int n, m;

int bfs(int x, int y, int tx, int ty){
	queue<pair<int, int>>q;
	q.push({ x, y });
	visited[x][y] = true;

	memset(visited, false, sizeof(visited));
	memset(dist, false, sizeof(dist));
	while (!q.empty()){
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++){
			int sx = xx + dx[i];
			int sy = yy + dy[i];
			if (sx < m && sx >= 0 && sy < n && sy >= 0 && !visited[sx][sy]){//범위내에 있고 방문 안했을때
				if (arr[sx][sy] == '*' || arr[sx][sy] == '.' || arr[sx][sy] == 'o')//가구가 아닌곳이면 방문 체크
				{
					visited[sx][sy] = true;
					q.push({ sx, sy });
					dist[sx][sy] = dist[xx][yy] + 1;
				}
			}
		}
	}

	return dist[tx][ty];
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<pair<int, int>>dirtlist;
	while (1){

		cin >> n >> m;

		if (n == 0 && m == 0) break; //프로그램 종료

		bool IsAble = true;
		int minnum = -1;
		dirt = 0;
		memset(dirtdist, 0, sizeof(dirtdist));
		dirtlist.clear();
		int cx, cy;//현재 로봇위치

		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				cin >> arr[i][j];
				if (arr[i][j] == '*') {
					dirt++;
					dirtlist.push_back({ i, j });
				}

				else if (arr[i][j] == 'o'){
					cx = i, cy = j;
				}
			}
		}

		if (dirt == 0) { //더러운 방 갯수가 0개이면 할 필요없음
			cout << 0 << "\n";
			continue;
		}

		//현재 위치 찾아서 더러운방 갯수만큼 bfs
		//현재 위치~더러운방까지의 거리
		for (int i = 0; i < dirt; i++){
			dirtdist[11][i] = bfs(cx, cy, dirtlist[i].first, dirtlist[i].second);
			//만약 거리가 0이라면 갈수 없는 것임
			if (dirtdist[11][i] == 0) {
				IsAble = false;
				break;
			}
		}

		if (!IsAble) { //갈 수 없으면 이번에 안함
			cout << -1 << "\n";
			continue;
		}

		//각 더러운 방마다 거리 서로 구하기
		for (int i = 0; i < dirt; i++){
			for (int j = i + 1; j < dirt; j++){
				int tmpdist = bfs(dirtlist[i].first, dirtlist[i].second, dirtlist[j].first, dirtlist[j].second);
				dirtdist[i][j] = tmpdist;
				dirtdist[j][i] = tmpdist;
			}
		}

		vector<int>v;
		for (int i = 0; i < dirt; i++){
			v.push_back(i);
		}
		//next_permutation으로 각 더러운 방 사이의 최소거리 구하기
		do{
			int ans = 0;

			ans += dirtdist[11][v[0]];//현위치에서 제일 첫번째꺼 거리
			for (int i = 0; i < dirt - 1; i++){
				ans += dirtdist[v[i]][v[i + 1]];
			}

			if (minnum > ans || minnum == -1){
				minnum = ans;
			}
		} while (next_permutation(v.begin(), v.end()));


		if (minnum == 0)cout << -1 << "\n";
		else cout << minnum << "\n";
	}
	return 0;
}