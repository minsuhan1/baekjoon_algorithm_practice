#include <iostream>
#include <string>
using namespace std;

void nbin(int n) {
	if (n == 0) {
		return;
	}
	if (n % 2 == 0) {
		nbin(-(n / 2));
		cout << 0;
	}
	else {	// �������� ������ �� ����.
		if (n > 0) {	// ��� ������
			nbin(-(n / 2));
		}
		else {	// ���� ������
			nbin((-n + 1) / 2);	// ex. n=-13�̸� ��=7 ������ 1
		}
		cout << 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int n;
	string ans = "";
	cin >> n;

	if (n == 0) {
		cout << 0 << '\n';
	}
	else {
		nbin(n);
	}

	return 0;
}