#include <iostream>
#include <vector>
using namespace std;

// 소수 판별: n이 소수인가?
bool prime(int n) {
	if (n < 2) {
		return false;
	}
	// N이 소수가 아니라면, N = a * b (a <= b)
	// 두 수 a와 b의 차이가 가장 작은 경우는 a <= 루트 N, b >= 루트 N
	// 따라서 N이 소수가 되려면, 2보다 크거나 같고
	// 루트N 보다 작거나 같은 자연수로 나누어 떨어지면 안된다.(검사를 루트N까지만 해보면 된다)
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