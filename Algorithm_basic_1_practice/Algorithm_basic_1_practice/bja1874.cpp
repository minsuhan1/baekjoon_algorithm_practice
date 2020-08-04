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

	int num = 0;	// ���ÿ� ���� �� ����
	stack<int> s;
	string result;
	bool v = true;	// ���� ���� ����/�Ұ��� ����(�ʱⰪ true)

	int n;
	cin >> n;
	// ���� ��� ����
	for (int i = 0; i < n; i++) {	// push �ݺ�Ƚ�� = n
		s.push(++num);
		result += "+\n";
	}
	s.pop();
	result += "-\n";
	test_num--;

	while (test_num--) {
		int n;
		cin >> n;
		if ((!s.empty() && n >= s.top() && v == true) || (s.empty() && v == true)) {
			int rep = n - num;
			for (int i = 0; i < rep; i++) {	
				// push �ݺ�Ƚ��(������Ű�� ���� rep ���� ���) = n - num
				s.push(++num);
				result += "+\n";
			}
			s.pop();
			result += "-\n";
		}
		else if (!s.empty() && n < s.top() && v == true) {
			// ���� ���� ���� �Ұ��� : ���� �� �� ���ڰ� n���� ũ�Ƿ�
			// n�� ���ÿ��� �ٷ� ���� �� ���� -> n���� ���� �ִ� ���ڰ� pop�ǹǷ� NO ���
			result = "NO";
			v = false;
		}
	}

	std::cout << result;
	return 0;
}