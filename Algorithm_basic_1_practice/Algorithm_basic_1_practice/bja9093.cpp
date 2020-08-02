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
	// cin 은 변수에 '\n'을 담지 않고 입력버퍼에 남겨둔다.
	// getline은 '\n'을 변수에 담는다.
	// 따라서 cin이 남겨둔 '\n'을 getline이 변수에 담지 않도록
	// 맨 앞의 문자 하나를 지우는 cin.ignore()를 사용하여 '\n'을 제거한다.

	while (test_num--) {
		string str;
		getline(cin, str);	// getline(읽어올 입력 스트림, 저장할 문자열 변수)
		str += '\n';
		stack<char> s;	// 스택
		for (char ch : str) {
			// 공백이나 엔터를 만날 때까지 push
			// 공백이나 엔터를 만나면 하나의 단어를 스택에 넣은 것이므로
			// 스택을 비운다.
			if (ch == ' ' || ch == '\n') {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << ch;
			}else {
				s.push(ch);
			}
		}
	}
	return 0;
}