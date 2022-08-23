#include <iostream>
using namespace std;

// ��Ŭ���� ȣ�������� ���ϴ� �ִ�����(GCD)
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	cin >> a >> b;

	cout << gcd(a, b) << endl;
	// �ּҰ���� = (a * b) / �ִ�����
	cout << (a * b) / gcd(a, b) << endl;
	return 0;
}