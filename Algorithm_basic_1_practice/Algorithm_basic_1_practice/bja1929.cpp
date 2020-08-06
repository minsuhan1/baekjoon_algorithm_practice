#include <iostream>
#include <vector>
using namespace std;

// �Ҽ� �Ǻ�: 1���� N���� ���� �ȿ� ���� ��� �Ҽ� ���ϱ�
// �����佺�׳׽��� ü
// 1. 2���� N���� ��� ���� ����´�.
// 2. ���� �������� ���� �� �� ���� ���� ���� ã�´�.
// 3. �� ���� �Ҽ��̴�.
// 4. ���� �� ���� ����� ��� �����.
// 1~4 ������ �ݺ��Ѵ�.


const int MAX = 1000000;
bool check[MAX + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// �����佺�׳׽��� ü
	check[0] = check[1] = true;
	for (int i = 2; i * i <= MAX; i++) {
		if (check[i] == false) {
			for (int j = i + i; j <= MAX; j += i) {
				check[j] = true;	// ������
			}
		}
	}

	int m, n;
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		if (check[i] == false) {
			cout << i << '\n';
		}
	}

	return 0;
}