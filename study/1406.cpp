#include <iostream>
#include <string>
#include <stack>
#include <list>

using namespace std;
int main() {
	char s[100000];
	char ch;

	int n;
	scanf("%s", &s);
	cin >> n;
	getchar();

	stack<char> stack_left;
	stack<char> stack_right;
	
	for (int i = 0; i < 100000; i++)
	{
		if (s[i] == '\0') break;
		stack_left.push(s[i]);

	}

	while (n--) {
		scanf("%c", &ch);
		getchar();
		switch (ch) {

		case 'L': if (!stack_left.empty()) { stack_right.push(stack_left.top()); stack_left.pop(); } break;
		case 'D': if (!stack_right.empty()) { stack_left.push(stack_right.top()); stack_right.pop(); } break;
		case 'B': if (!stack_left.empty()) { stack_left.pop(); } break;
		case 'P': char ch2; scanf("%c", &ch2); getchar(); stack_left.push(ch2); break;
		default: break;
		}
	}

	n = stack_left.size();
	for (int i=0;i<n;i++){
		stack_right.push(stack_left.top());
		stack_left.pop();
	}
	
	n = stack_right.size();
	for (int i = 0; i < n; i++) {
		cout << stack_right.top();
		stack_right.pop();
	}

	return 0;
}
