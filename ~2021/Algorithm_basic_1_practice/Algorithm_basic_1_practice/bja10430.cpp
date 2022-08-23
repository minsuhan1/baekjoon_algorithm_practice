#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;

	cout << (a + b) % c << endl;
	cout << ((a % c) + (b % c)) % c << endl;
	// 이 둘은 같다.

	cout << (a * b) % c << endl;
	cout << ((a % c) * (b % c)) % c << endl;
	// 이 둘은 같다.
	return 0;
}