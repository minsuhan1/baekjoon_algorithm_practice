#include <iostream>
#include <vector>
using namespace std;

// �Ҽ� �Ǻ�: n�� �Ҽ��ΰ�?
bool prime(int n) {
	if (n < 2) {
		return false;
	}
	// N�� �Ҽ��� �ƴ϶��, N = a * b (a <= b)
	// �� �� a�� b�� ���̰� ���� ���� ���� a <= ��Ʈ N, b >= ��Ʈ N
	// ���� N�� �Ҽ��� �Ƿ���, 2���� ũ�ų� ����
	// ��ƮN ���� �۰ų� ���� �ڿ����� ������ �������� �ȵȴ�.(�˻縦 ��ƮN������ �غ��� �ȴ�)
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int ans = 0;
	int n;
	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (prime(a[i])) ans++;
	}
	
	cout << ans;

	return 0;
}