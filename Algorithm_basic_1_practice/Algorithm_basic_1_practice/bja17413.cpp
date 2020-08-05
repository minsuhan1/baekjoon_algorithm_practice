#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	getline(cin, str);	// getline(�о�� �Է� ��Ʈ��, ������ ���ڿ� ����)
	str += '\n';
	stack<char> s;	// ����
	bool valid = true;		// ���� ���ڰ� ���ÿ� �Էµ� �� �ִ� �������� ����(< > ���� ���ڴ� false)

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