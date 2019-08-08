#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

queue < pair<pair<int, int>, pair<int, int>>>q;
int visited[101][101];
char arr[101][101];
int dist[101][101];
int h, w;
int dx[4] = { 0,0,1,-1 };//오,왼,아,위
int dy[4] = { 1,-1,0,0 };
vector < pair<int, int>>v;
int minnum = 1e10;
bool checkCon(int x, int y) {
	return (x >= 0 && x < h && y >=0 && y < w);
}

//최소거리찾기
int bfs_dist(int a, int b) {

	visited[a][b] = 0;
	for (int i = 0; i < 4; i++) {
		q.push({ {a,b},{i,0} });
	}
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int before = q.front().second.first;
		int mirror_cnt = q.front().second.second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;//오,왼,아,위
			int ny = dy[i] + y;
			int cnt = mirror_cnt;
			if (i != before) cnt ++; //전의 움직임이랑 이번 움직임이랑 다르면 mirror 쓴 것
			if (checkCon(nx, ny) && arr[nx][ny]!='*') {
				if (visited[nx][ny] >= cnt) {
					visited[nx][ny] = cnt;

					q.push({ { nx,ny },{i,cnt } });
				}
				
			}
		}
	}
	return visited[v[0].first][v[0].second];

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> w >> h;
	memset(visited, 0x3f3f3f, sizeof(visited)); //visited 
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'C') v.push_back({ i,j });
		}
	}
	int a=v[1].first;
	int b=v[1].second;
	v.pop_back();
	
	cout<<bfs_dist(a, b);

	
	return 0;
}
