#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
int n;
int alphabet[26];
string s;
int main() {
	cin >> n;
	//ABCDE이면 A=10000,B=1000,C=100,D=10,E=1 이런식으로 알파벳과 자릿수 매핑
	for (int i = 0; i < n; i++) {
		cin >> s;
		int sizeString = s.length();
		for (int j = 0; j < sizeString; j++) {
			alphabet[s[j] - 65] += pow(10, sizeString - 1 - j);
		}
		
	}

	int ans = 0;
	vector<int>v;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > 0) {
			v.push_back(alphabet[i]);
		}
	}
	int cnt = 9;
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < v.size(); i++) {
		ans += v[i] * (cnt--);
	}
	cout << ans << "\n";
	return 0;
}
