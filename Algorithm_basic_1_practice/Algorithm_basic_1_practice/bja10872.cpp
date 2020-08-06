#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	int ans = 1;

	while (n>0) {
		ans *= n;
		n--;
	}

	cout << ans;

	return 0;
}