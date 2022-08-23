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

	stack<char> ls;	// Ŀ�� ���� ���ڿ��� ��� ����
	stack<char> rs;	// Ŀ�� ������ ���ڿ��� ��� ����

	for (int i = 0; i < str.length(); i++) {
		ls.push(str.at(i));
	}

	while (test_num--) {
		string cmd;
		cin >> cmd;

		// ���� ���ڿ� : algori|thm (|�� Ŀ��)
		// right stack�� top : i
		// left stack�� top : t

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

	// ���� ���ÿ� ����ִ� ���ڵ��� ���ʷ� pop�Ͽ� ������ ���ÿ� push
	// ������ ������ ���ʷ� pop�Ͽ� ���� ���ڿ� ���
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