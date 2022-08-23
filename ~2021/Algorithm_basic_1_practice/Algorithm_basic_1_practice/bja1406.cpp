#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;

	int test_num;
	cin >> test_num;
	cin.ignore();

	stack<char> ls;	// 커서 왼쪽 문자열을 담는 스택
	stack<char> rs;	// 커서 오른쪽 문자열을 담는 스택

	for (int i = 0; i < str.length(); i++) {
		ls.push(str.at(i));
	}

	while (test_num--) {
		string cmd;
		cin >> cmd;

		// 예시 문자열 : algori|thm (|는 커서)
		// right stack의 top : i
		// left stack의 top : t

		if (cmd == "L" && !ls.empty()) {
			rs.push(ls.top());
			ls.pop();
		}

		if (cmd == "D" && !rs.empty()) {
			ls.push(rs.top());
			rs.pop();
		}

		if (cmd == "B" && !ls.empty()) {
			ls.pop();
		}

		if (cmd == "P") {
			char add;
			cin >> add;
			ls.push(add);
		}
	}

	// 왼쪽 스택에 들어있는 문자들을 차례로 pop하여 오른쪽 스택에 push
	// 오른쪽 스택을 차례로 pop하여 최종 문자열 출력
	while (!ls.empty()) {
		rs.push(ls.top());
		ls.pop();
	}
	while (!rs.empty()) {
		cout << rs.top();
		rs.pop();
	}
	
	return 0;
}