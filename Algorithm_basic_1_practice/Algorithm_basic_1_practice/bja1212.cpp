#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	string ans = "";
	cin >> s;
	int n = s.size();

	// 0���� 7������ ���� ������ 2������ string �迭�� �����Ͽ� ����ϴ� ����� ������
	// ���⼭�� 8������ 2������ ��ȯ�ϴ� ������ �����Ͽ���.
	// �̸� 2�������� �迭�� �����ϸ� �ð��� �ξ� ���� �ɸ���.
	for (int i = 0; i < n; i++) {
		int a = s[i] - '0';
		int r[3];
		// 8���� a�� 2������ ��ȯ�ϴ� ����
		for (int i = 0; i < 3; i++) {
			r[i] = a % 2;	// a�� 2�� ���� �������� ����
			a = a / 2;		// a�� 2�� ���� ���� a�� �ȴ�
		}
		// �������� �Ųٷ� ����
		ans += to_string(r[2]);
		ans += to_string(r[1]);
		ans += to_string(r[0]);
	}

	if (ans[0] == '0') {
		if (ans[1] == '0') {
			cout << ans.substr(2);
		}
		else {
			cout << ans.substr(1);
		}
	}
	else {
		cout << ans;
	}

	return 0;
}