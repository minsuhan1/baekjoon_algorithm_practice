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
	cout.tie(nullptr);

	int n;
	cin >> n;

	while (n--) {
		int a, b;
		cin >> a >> b;

		// �ּҰ���� = (a * b) / �ִ�����
		cout << (a * b) / gcd(a, b) << endl;
	}
	
	return 0;
}