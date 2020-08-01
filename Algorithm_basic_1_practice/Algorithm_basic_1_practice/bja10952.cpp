#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int a, b;
	while (cin >> a >> b && (a != 0) && (b != 0)) {
		cout << a + b << endl;
	}
}