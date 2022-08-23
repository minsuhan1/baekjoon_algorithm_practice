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

int a[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testN;
	cin >> testN;

	while (testN--) {
		int n;
		long long sum = 0;	// int 면 부족하다.
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n-1; i++) {	// 가능한 모든 쌍
			for (int j = i+1; j < n; j++) {
				sum += gcd(a[i], a[j]);
			}
		}
		cout << sum << '\n';
	}

	return 0;
}