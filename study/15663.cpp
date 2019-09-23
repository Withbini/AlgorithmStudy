#include<iostream>
#include<algorithm>

using namespace std;
int num[8];
int visited[8];
int ans[8];
int n, k;

void dfs(int step)
{
	if (step == k)
	{
		for (int i = 0; i < k; i++)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}

	int check[10001] = { 0, };
	for (int i = 0; i < n; i++)
	{
		//방문하지 않았고 그 숫자도 안썼음
		if (!check[num[i]] && !visited[i])
		{
			visited[i] = true;
			check[num[i]] = 1;
			ans[step] = num[i];
			dfs(step + 1);
			visited[i] = false;
		}
	}

}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num, num + n);

	dfs(0);

	return 0;
}
