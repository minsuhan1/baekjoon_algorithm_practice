#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	getline(cin, str);	// getline(읽어올 입력 스트림, 저장할 문자열 변수)
	str += '\n';
	stack<char> s;	// 스택
	bool valid = true;		// 현재 문자가 스택에 입력될 수 있는 문자인지 여부(< > 안의 문자는 false)

	for (char ch : str) {
		if (ch == '>') {
			valid = true;
			cout << ch;
			continue;
		}

		if (!valid) {
			cout << ch;
		}
		else {
			if (ch == ' ' || ch == '<' || ch == '\n') {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				if (ch == '<') {
					valid = false;
				}
				cout << ch;
			}
			else {
				s.push(ch);
			}
		}
		
	}

	return 0;
}