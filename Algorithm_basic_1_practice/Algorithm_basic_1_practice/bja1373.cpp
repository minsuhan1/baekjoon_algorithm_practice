#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	if (n % 3 == 1) {	// 뒤에서부터 3자리씩 끊었을 때 1자리 남음
		cout << s[0];
	}
	else if (n % 3 == 2) {	// 뒤에서부터 3자리씩 끊었을 때 2자리 남음
		cout << (s[0] - '0') * 2 + (s[1] - '0');
	}
	for (int i = n % 3; i < n; i+=3) {
		cout << (s[i] - '0') * 4 + (s[i + 1] - '0') * 2 + (s[i + 2] - '0');
	}
	cout << '\n';
	return 0;
}