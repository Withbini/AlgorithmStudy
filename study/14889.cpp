#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int ans = 12345678;
int visited[21];
int s[21][21];
void permutation(int x, int cnt) {

	//뽑은 횟수
	if (cnt == n / 2) {
		vector<int> team_l, team_s;

		//방문했으면 team s 안했으면 team l
		for (int i = 0; i < n; i++)
		{
			if (visited[i]) team_s.push_back(i);
			else team_l.push_back(i);
		}

		// 스타트팀과 링크팀의 능력치 차이 구하기
		int stat_s = 0, stat_l = 0;
		for (int i = 0; i < team_s.size(); i++)
		{
			for (int j = i + 1; j < team_s.size(); j++)
			{
				stat_s += s[team_s[i]][team_s[j]] + s[team_s[j]][team_s[i]];
				stat_l += s[team_l[i]][team_l[j]] + s[team_l[j]][team_l[i]];
			}
		}

		ans = min(ans, abs(stat_s - stat_l));
		return;
	}

	//방문 여부만 확인
	for (int i = x + 1; i < n; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			permutation(i, cnt + 1);
			visited[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> s[i][j];
		}
	}

	permutation(0, 0);
	cout << ans << "\n";
	return 0;
}
