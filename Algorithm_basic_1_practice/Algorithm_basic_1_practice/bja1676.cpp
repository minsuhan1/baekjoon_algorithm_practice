#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	// 2�� ����� ������ 5�� ����� �������� �׻� ����.
	// ���� 5�� ����� ã�������� 0�� ������ �ϳ��� �þ��.
	// �������� N<=500�̹Ƿ� 25�� ���, 125�� ����� 5�� ���� 1��,2���� �� ��������.

	int ans = (n / 5);
	if (n >= 25) {
		ans += (n / 25);
	}
	if (n >= 125) {
		ans += (n / 125);
		// 25�� ������� ã�� ans++ �Ͽ����Ƿ�
		// ans += 2�� �ƴ� ans++
	}
	cout << ans;

	return 0;
}