#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

int main() {
	int a, b, n;
	char s[10];
	cin >> n;

	while (n--) {
		scanf("%s", s);
		a = atoi(&s[0]);
		b = atoi(&s[2]);
		printf("%d\n", a + b);
	}
	
	return 0;
}
