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
	// cin �� ������ '\n'�� ���� �ʰ� �Է¹��ۿ� ���ܵд�.
	// getline�� '\n'�� ������ ��´�.
	// ���� cin�� ���ܵ� '\n'�� getline�� ������ ���� �ʵ���
	// �� ���� ���� �ϳ��� ����� cin.ignore()�� ����Ͽ� '\n'�� �����Ѵ�.

	while (test_num--) {
		string str;
		getline(cin, str);	// getline(�о�� �Է� ��Ʈ��, ������ ���ڿ� ����)
		str += '\n';
		stack<char> s;	// ����
		for (char ch : str) {
			// �����̳� ���͸� ���� ������ push
			// �����̳� ���͸� ������ �ϳ��� �ܾ ���ÿ� ���� ���̹Ƿ�
			// ������ ����.
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