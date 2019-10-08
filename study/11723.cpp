#include <iostream>
#include <cstdio>

using namespace std;
int s[21];
void setcheck(char a,int input) {
	switch (a) {
		//add
	case 'd': if(s[input]!=1) s[input]=1;
		break;
		//remove
	case 'e':if (s[input] == 1) s[input] = 0; break;
		//check
	case 'h':if (s[input] == 1) cout << 1<<"\n"; else cout << 0<<"\n";  break;
		//toggle
	case 'o':if (s[input] == 1) s[input] = 0; else s[input] = 1; break;
	case 'l':for (int i = 1; i < 21; i++) s[i]=1; break;
	case 'm':for (int i = 1; i < 21; i++) s[i]=0; break;
	default: break;
	}
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		char a[6];
		int input;
		scanf("%s %d", &a, &input);
		setcheck(a[1], input);
	}
	return 0;
}
