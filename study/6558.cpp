#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>

using namespace std;
int arr[1000001];
int numprime = 0;
bool isnotPrime[1000001] ;


void getPrime() {
	int n = 1000000;
	for (int i = 2; i <= n; i++) {
		if (isnotPrime[i] == false) {
			arr[numprime++] = i;
			for (int j = 2 * i; j <= n; j += i) {
				isnotPrime[j] = true;
			}
		}
	}
}

int main() {
	int n;
	
	getPrime();
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (1) {
		cin >> n;
		if (n == 0) break;
		for (int i = 1; i < numprime; i++) {
			if (isnotPrime[n - arr[i]] == false) {
				cout << n << " = " << arr[i] << " + " << n - arr[i] << '\n';
				break;
			}
		}
	}
	return 0;
}
