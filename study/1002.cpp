#include <iostream>
#include<math.h>

using namespace std;
typedef struct _point {
	long long x;
	long long y;
}POINT;

int dist(POINT p1, POINT p2) {
	return ((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}
int main() {
	POINT p[2];
	int t;
	cin >> t;
	while (t--) {
		int r[2];
		cin >> p[0].x >> p[0].y;
		cin >> r[0];
		cin >> p[1].x >> p[1].y;
		cin >> r[1];

		int ans = 0;
		int d = dist(p[0], p[1]);
		int sum = r[0] + r[1];
		sum = sum * sum;
		int diff = abs(r[0] - r[1]);
		diff = diff * diff;

		if (sum > d && diff < d) ans = 2;
		else if ((sum == d) || (diff == d&& d != 0)) ans = 1;
		else if (sum < d || diff >d)  ans = 0;
		else if (d == 0) {
			if (r[0] == r[1]) ans = -1;
			else ans = 0;
		}

		cout << ans << "\n";
	}

	return 0;
}