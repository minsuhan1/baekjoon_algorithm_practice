#include <iostream>
#include <string>
using namespace std;

void nbin(int n) {
	if (n == 0) {
		return;
	}
	if (n % 2 == 0) {
		nbin(-(n / 2));
		cout << 0;
	}
	else {	// 나머지는 음수일 수 없다.
		if (n > 0) {	// 양수 나눗셈
			nbin(-(n / 2));
		}
		else {	// 음수 나눗셈
			nbin((-n + 1) / 2);	// ex. n=-13이면 몫=7 나머지 1
		}
		cout << 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int n;
	string ans = "";
	cin >> n;

	if (n == 0) {
		cout << 0 << '\n';
	}
	else {
		nbin(n);
	}

	return 0;
}