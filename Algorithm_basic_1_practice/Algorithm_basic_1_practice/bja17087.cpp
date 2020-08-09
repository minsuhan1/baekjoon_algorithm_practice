#include <iostream>
using namespace std;

// 유클리드 호제법으로 구하는 최대공약수(GCD)
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int a[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	long long s;
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = abs(s - a[i]);
	}
	
	int ans = a[0];
	for (int i = 1; i < n; i++) {
		ans = gcd(ans, a[i]);
	}
	// 예시: 6 12 4 8
	// gcd(6, 12) = 6 -> gcd(6, 4) = 2 -> gcd(2, 8) = 2
	// ans = 2

	cout << ans << '\n';
	return 0;
}