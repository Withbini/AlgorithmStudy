#include <iostream>
#include <cstring>
using namespace std;
int d[10001][3];
int main(){
	int t;
	cin >> t;

	memset(d, 0, sizeof(d));
	d[1][0] = 1, d[1][1] = 0, d[1][2] = 0;
	d[2][0] = 1, d[2][1] = 1, d[2][2] = 0;
	d[3][0] = 1, d[3][1] = 1, d[3][2] = 1;
	//d[n][i] :n��° ������ 1,2,3���� ǥ���ϴµ�
	//i�� �����ϴ� ����� ��
	for (int i = 4; i < 10001; i++){
		d[i][0] = d[i - 1][0];
		d[i][1] = d[i - 2][0] + d[i - 2][1];
		d[i][2] = d[i - 3][0] + d[i - 3][1] + d[i - 3][2];

	}

	while (t--){
		int n;
		cin >> n;
		cout << d[n][0] + d[n][1] + d[n][2]<<"\n";
	}
	return 0;
}