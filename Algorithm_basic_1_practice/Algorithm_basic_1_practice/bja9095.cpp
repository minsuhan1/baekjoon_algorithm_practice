#include <iostream>
using namespace std;

int d[11];

int cal(int n) {
	if (d[n] > 0) return d[n];
	if (n - 1 >= 0)
		d[n] += cal(n - 1);
	if (n - 2 >= 0)
		d[n] += cal(n - 2);
	if (n - 3 >= 0)
		d[n] += cal(n - 3);
	return d[n];
}

int main() {
	d[0] = 1;
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << cal(n) << '\n';
	}
}