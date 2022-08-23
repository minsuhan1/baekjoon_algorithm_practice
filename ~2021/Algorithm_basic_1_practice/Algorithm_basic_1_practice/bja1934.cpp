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
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	while (n--) {
		int a, b;
		cin >> a >> b;

		// 최소공배수 = (a * b) / 최대공약수
		cout << (a * b) / gcd(a, b) << endl;
	}
	
	return 0;
}