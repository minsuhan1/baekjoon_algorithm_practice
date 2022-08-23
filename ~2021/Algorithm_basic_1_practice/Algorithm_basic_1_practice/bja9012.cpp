#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int test_num;
	cin >> test_num;
	cin.ignore();

	while (test_num--) {
		string str;
		getline(cin, str);
		str += '\n';
		stack<char> s;	// 여는괄호를 넣을 스택
		bool isVPS = true;
		for (char ch : str) {
			if (ch == '(') {
				s.push(ch);	// 여는괄호이면 스택에 push
			}
			else if (ch == ')' && !s.empty()) {
				s.pop();	// 닫는 괄호를 만날 때마다 스택의 맨 위 여는 괄호를 pop
			}
			else if (ch == ')' && s.empty()) {
				// "())" 과 같이 짝이 없는 닫는 괄호가 남는 경우 VPS(valid parenthesis string)가 아님
				isVPS = false;
			}
			if (ch == '\n') {
				break;
			}
		}// 문자열 끝에 도달
		if (!s.empty()) {	// "(()"와 같이 여는 괄호가 스택에 남는 경우 VPS가 아님
			isVPS = false;
		}

		if (isVPS)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}