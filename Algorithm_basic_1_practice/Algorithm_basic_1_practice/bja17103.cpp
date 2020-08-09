#include <iostream>
using namespace std;

bool a[1000001];

int main() {
	a[0] = a[1] = true;
	for (int i = 2; i < 1000001; i++) {
		if (a[i] == false) {
			for (int j = i * 2; j < 1000001; j += i) {
				a[j] = true;
			}
		}
	}

	int t, n;
	cin >> t;

	while (t--) {
		int ans = 0;
		cin >> n;
		for (int i = 2; i <= n/2; i++) {	
			// 순서만 바뀐 경우는 1개로 간주하기 위해 i <= n/2

			if (a[i] == false && a[n - i] == false) {
				ans++;
			}
		}
		cout << ans << '\n';
	}
}

