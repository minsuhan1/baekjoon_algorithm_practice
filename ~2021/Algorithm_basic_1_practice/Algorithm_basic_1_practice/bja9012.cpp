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
		stack<char> s;	// ���°�ȣ�� ���� ����
		bool isVPS = true;
		for (char ch : str) {
			if (ch == '(') {
				s.push(ch);	// ���°�ȣ�̸� ���ÿ� push
			}
			else if (ch == ')' && !s.empty()) {
				s.pop();	// �ݴ� ��ȣ�� ���� ������ ������ �� �� ���� ��ȣ�� pop
			}
			else if (ch == ')' && s.empty()) {
				// "())" �� ���� ¦�� ���� �ݴ� ��ȣ�� ���� ��� VPS(valid parenthesis string)�� �ƴ�
				isVPS = false;
			}
			if (ch == '\n') {
				break;
			}
		}// ���ڿ� ���� ����
		if (!s.empty()) {	// "(()"�� ���� ���� ��ȣ�� ���ÿ� ���� ��� VPS�� �ƴ�
			isVPS = false;
		}

		if (isVPS)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}