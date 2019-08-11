#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
vector<int> a(n);

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m;
		a.push_back(m);
	}
	if (prev_permutation(a.begin(), a.end())) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
	}
	else {
		cout << "-1";
	}
	cout << '\n';
	return 0;
}
