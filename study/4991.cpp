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
int dirtdist[12][12];//������ �波�� �Ÿ�
int dirt = 0;//������氹��
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
			if (sx < m && sx >= 0 && sy < n && sy >= 0 && !visited[sx][sy]){//�������� �ְ� �湮 ��������
				if (arr[sx][sy] == '*' || arr[sx][sy] == '.' || arr[sx][sy] == 'o')//������ �ƴѰ��̸� �湮 üũ
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

		if (n == 0 && m == 0) break; //���α׷� ����

		bool IsAble = true;
		int minnum = -1;
		dirt = 0;
		memset(dirtdist, 0, sizeof(dirtdist));
		dirtlist.clear();
		int cx, cy;//���� �κ���ġ

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

		if (dirt == 0) { //������ �� ������ 0���̸� �� �ʿ����
			cout << 0 << "\n";
			continue;
		}

		//���� ��ġ ã�Ƽ� ������� ������ŭ bfs
		//���� ��ġ~������������ �Ÿ�
		for (int i = 0; i < dirt; i++){
			dirtdist[11][i] = bfs(cx, cy, dirtlist[i].first, dirtlist[i].second);
			//���� �Ÿ��� 0�̶�� ���� ���� ����
			if (dirtdist[11][i] == 0) {
				IsAble = false;
				break;
			}
		}

		if (!IsAble) { //�� �� ������ �̹��� ����
			cout << -1 << "\n";
			continue;
		}

		//�� ������ �渶�� �Ÿ� ���� ���ϱ�
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
		//next_permutation���� �� ������ �� ������ �ּҰŸ� ���ϱ�
		do{
			int ans = 0;

			ans += dirtdist[11][v[0]];//����ġ���� ���� ù��°�� �Ÿ�
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