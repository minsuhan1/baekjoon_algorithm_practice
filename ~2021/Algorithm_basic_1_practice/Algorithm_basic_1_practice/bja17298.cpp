#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);	// �Է�
	vector<int> ans(n);	// ��

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	stack<int> s;
	s.push(0);	// ù��° ���ڴ� ��ū���� ���� ã�� �� �����Ƿ� ���ÿ� ����

	for (int i = 1; i < n; i++) {

		while (!s.empty() && a[s.top()] < a[i]) {
			// ������ ��� ���� �ʰ�
			// ������ �� �� �ε����� ����Ű�� ���� a[s.top()] ���� i��° ���ڰ� �� ũ��
			// i��° ���ڴ� a[s.top()]�� ��ū���̴�.
			// �̰��� ������ ��ų�, ���ÿ� ���� �ִ� ���� �� i��° ���ں��� ū ���� ���ö����� �ݺ��Ѵ�.
			ans[s.top()] = a[i];
			s.pop();
		}
		// ������ ��ų�, ���ÿ� ���� �ִ� ���� �� i��° ���ں��� ū ���� ���� ���
		// �ε��� i�� ���ÿ� �ִ´�.
		s.push(i);

	}
	// �� �������� ���ÿ� �����ִ� �ε������� ��ū���� ���� �ε����̴�.
	while (!s.empty()) {
		ans[s.top()] = -1;	// �̵��� ���� -1
		s.pop();
	}

	for (int a : ans) {
		cout << a << " ";	// �� ���
	}

	return 0;
}