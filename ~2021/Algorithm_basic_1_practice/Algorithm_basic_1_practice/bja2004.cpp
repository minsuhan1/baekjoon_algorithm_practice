#include <iostream>
using namespace std;

/*
���� nCm�� 0�� ����
nCm = n! / ((n-m)! m!)
n!, (n-m)!, m! ������ 2, 5 ������ ���Ѵ���
n!���� ���� 2, 5 �������� (n-m)!, m!���� ���� 2, 5 ������ ���� ����
�� ��� 2�� ������ 5�� ���� �� ���� ���� nCm�� 0�� �����̴�.
*/
int findTwo(int n) {
	int t = 0;
	for (long long i = 2; i <= 2000000000 && n >= i; i *= 2) {
		t += (n / i);
	}
	return t;
}
int findFive(int n) {
	int f = 0;
	for (long long i = 5; i <= 2000000000 && n >= i; i *= 5) {
		f += (n / i);
	}
	return f;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, ans;
	cin >> n >> m;
	int t = 0, f = 0;	// ���� 2�� 5�� ����

	t = findTwo(n) - findTwo(n - m) - findTwo(m);
	f = findFive(n) - findFive(n - m) - findFive(m);
	
	ans = (t < f) ? t : f;
	cout << ans;

	return 0;
}