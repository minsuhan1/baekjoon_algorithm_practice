#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;
bool check[MAX + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// �����佺�׳׽��� ü�� �̿��Ͽ� �Ҽ��� �ƴ� ���� �ɷ�����.
	check[0] = check[1] = true;
	for (int i = 2; i * i <= MAX; i++) {
		if (check[i] == false) {
			for (int j = i + i; j <= MAX; j += i) {
				check[j] = true;	// ������
			}
		}
	}
	
	int n;
	while (cin >> n && n != 0) {
		for (int i = 2; i <= n; i++) {
			if (check[i] == false && check[n-i] == false) {
				cout << n << " = " << i << " + " << n-i << '\n';
				break;
			}
		}
	}
	

	return 0;
}