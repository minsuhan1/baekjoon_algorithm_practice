#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	string ans = "";
	cin >> s;
	int n = s.size();

	// 0부터 7까지에 대한 각각의 2진수를 string 배열에 저장하여 출력하는 방법도 있으나
	// 여기서는 8진수를 2진수로 변환하는 과정을 포함하였다.
	// 미리 2진수들을 배열에 저장하면 시간은 훨씬 적게 걸린다.
	for (int i = 0; i < n; i++) {
		int a = s[i] - '0';
		int r[3];
		// 8진수 a를 2진수로 변환하는 과정
		for (int i = 0; i < 3; i++) {
			r[i] = a % 2;	// a를 2로 나눈 나머지를 저장
			a = a / 2;		// a를 2로 나눈 몫이 a가 된다
		}
		// 나머지를 거꾸로 쓴다
		ans += to_string(r[2]);
		ans += to_string(r[1]);
		ans += to_string(r[0]);
	}

	if (ans[0] == '0') {
		if (ans[1] == '0') {
			cout << ans.substr(2);
		}
		else {
			cout << ans.substr(1);
		}
	}
	else {
		cout << ans;
	}

	return 0;
}