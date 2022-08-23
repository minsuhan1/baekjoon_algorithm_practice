#include <iostream>
using namespace std;

/*
조합 nCm의 0의 개수
nCm = n! / ((n-m)! m!)
n!, (n-m)!, m! 각각의 2, 5 개수를 구한다음
n!에서 구한 2, 5 개수에서 (n-m)!, m!에서 구한 2, 5 개수를 각각 뺀다
뺀 결과 2의 개수와 5의 개수 중 작은 값이 nCm의 0의 개수이다.
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
	int t = 0, f = 0;	// 각각 2와 5의 개수

	t = findTwo(n) - findTwo(n - m) - findTwo(m);
	f = findFive(n) - findFive(n - m) - findFive(m);
	
	ans = (t < f) ? t : f;
	cout << ans;

	return 0;
}