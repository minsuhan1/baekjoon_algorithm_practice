#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	getline(cin, str);
	str += '\n';

	stack<int> s;	// ��ȣ �ε��� ����
	int ans = 0;
	int index = 1;	// ��ȣ�� �ε���(1���� ����)

	for (char ch : str) {
		if (ch == '(') {
			s.push(index);
			index++;
		}
		else if (ch == ')' && (index - s.top() == 1)) {	// ������
			s.pop();
			ans += s.size();	// s.size()���� ������ ����
		}
		else if (ch == ')' && (index - s.top() != 1)) {	// �踷����� ������ ��
			s.pop();
			ans += 1;	// 1���� ������ ����
		}
		if (ch == '\n') {
			break;
		}
	}// ���ڿ� ���� ����
	
	cout << ans;
	return 0;
}