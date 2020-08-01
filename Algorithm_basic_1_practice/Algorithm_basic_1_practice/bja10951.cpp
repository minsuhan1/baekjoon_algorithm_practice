#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int a, b;
	while(cin >> a >> b) {
		cout << a + b << endl;
	}
}

// EOF Âü°í: https://takeknowledge.tistory.com/20