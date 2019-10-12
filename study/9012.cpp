#include <iostream>
#include <string>
using namespace std;

string getValid(string s) {
	int cnt = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		if (s[i] == '(') cnt++;
		else cnt--;

		if (cnt < 0) return "NO";
	}

	if (cnt == 0) return "YES";
	else return "NO";
}
int main() {
	int n;
	string s;
	cin >> n;

	while (n--) {
		cin >> s;
		cout<<getValid(s)<<endl;
		}
	return 0;
}
