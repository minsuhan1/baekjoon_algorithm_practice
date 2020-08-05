#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);	// 입력
	vector<int> ans(n);	// 답

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	stack<int> s;
	s.push(0);	// 첫번째 숫자는 오큰수를 아직 찾을 수 없으므로 스택에 넣음

	for (int i = 1; i < n; i++) {

		while (!s.empty() && a[s.top()] < a[i]) {
			// 스택이 비어 있지 않고
			// 스택의 맨 위 인덱스가 가리키는 숫자 a[s.top()] 보다 i번째 숫자가 더 크면
			// i번째 숫자는 a[s.top()]의 오큰수이다.
			// 이것을 스택이 비거나, 스택에 남아 있는 숫자 중 i번째 숫자보다 큰 수가 나올때까지 반복한다.
			ans[s.top()] = a[i];
			s.pop();
		}
		// 스택이 비거나, 스택에 남아 있는 숫자 중 i번째 숫자보다 큰 수가 나온 경우
		// 인덱스 i를 스택에 넣는다.
		s.push(i);

	}
	// 이 시점에서 스택에 남아있는 인덱스들은 오큰수가 없는 인덱스이다.
	while (!s.empty()) {
		ans[s.top()] = -1;	// 이들의 답은 -1
		s.pop();
	}

	for (int a : ans) {
		cout << a << " ";	// 답 출력
	}

	return 0;
}