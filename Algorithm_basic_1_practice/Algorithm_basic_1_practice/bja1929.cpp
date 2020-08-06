#include <iostream>
#include <vector>
using namespace std;

// 소수 판별: 1부터 N까지 범위 안에 들어가는 모든 소수 구하기
// 에라토스테네스의 체
// 1. 2부터 N까지 모든 수를 써놓는다.
// 2. 아직 지워지지 않은 수 중 가장 작은 수를 찾는다.
// 3. 그 수는 소수이다.
// 4. 이제 그 수의 배수를 모두 지운다.
// 1~4 과정을 반복한다.


const int MAX = 1000000;
bool check[MAX + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 에라토스테네스의 체
	check[0] = check[1] = true;
	for (int i = 2; i * i <= MAX; i++) {
		if (check[i] == false) {
			for (int j = i + i; j <= MAX; j += i) {
				check[j] = true;	// 지워짐
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