#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, a, b;
	char c;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> c >> b;
		cout << a + b << endl;
	}
}
