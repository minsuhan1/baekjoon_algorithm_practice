#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	// 2의 배수의 개수가 5의 배수의 개수보다 항상 많다.
	// 따라서 5의 배수를 찾을때마다 0의 개수가 하나씩 늘어난다.
	// 문제에서 N<=500이므로 25의 배수, 125의 배수는 5가 각각 1번,2번씩 더 곱해진다.

	int ans = (n / 5);
	if (n >= 25) {
		ans += (n / 25);
	}
	if (n >= 125) {
		ans += (n / 125);
		// 25의 배수들을 찾아 ans++ 하였으므로
		// ans += 2가 아닌 ans++
	}
	cout << ans;

	return 0;
}